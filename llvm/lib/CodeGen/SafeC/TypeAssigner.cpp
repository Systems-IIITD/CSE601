#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/MDBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Use.h"
#include "llvm/IR/User.h"
#include "llvm/IR/Value.h"
#include "llvm/CodeGen/ValueTypes.h"
#include "llvm/CodeGen/Analysis.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Analysis/TargetLibraryInfo.h"
#include "llvm/Support/LowLevelTypeImpl.h"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

#include <deque>

using namespace llvm;

namespace {
struct TypeAssigner : public FunctionPass {
  static char ID;
  TypeAssigner() : FunctionPass(ID) {}

	unsigned long long computeBitMap(const DataLayout &DL, Type *Ty)
	{
		SmallVector<LLT, 8> ValueVTs;
    SmallVector<uint64_t, 8> Offsets;

		computeValueLLTs(DL, *Ty, ValueVTs, &Offsets);
		unsigned long long bitmap = 0;
		int bitpos = 0;

		for (unsigned i = 0; i < ValueVTs.size(); i++)
		{
			bitpos = Offsets[i] / 64;
			assert(bitpos < 63 && "can not handle more than 63 fields!");
			if (ValueVTs[i].isPointer())
			{
				bitmap |= (1ULL << bitpos); /* Fixed by Fahad Nayyar */
			}
		}

		if (bitmap)
		{
			auto Sz = DL.getTypeAllocSize(Ty);
			assert((Sz & 7) == 0 && "type is not aligned!");
			bitpos++;
			bitmap |= (1ULL << bitpos); /* Fixed by Fahad Nayyar */
		}
		return bitmap;
	}

  bool runOnFunction(Function &F) override {

		const DataLayout &DL = F.getParent()->getDataLayout();

		for (BasicBlock &BB : F)
		{
			for (Instruction &II : BB)
			{
				CallInst *CI = dyn_cast<CallInst>(&II);
				if (CI && CI->getType()->isPointerTy())
				{
					Function *Callee = CI->getCalledFunction();

					if (Callee && !Callee->getName().compare("mymalloc"))
					{
						Instruction *Next = II.getNextNode();
						if (isa<CastInst>(Next) && 
								Next->getType()->isPointerTy() && 
								Next->getOperand(0) == CI)
						{
							auto PTy = Next->getType()->getPointerElementType();
							auto ObjSz = DL.getTypeAllocSize(PTy);
							unsigned long long bitmap = computeBitMap(DL, PTy);

							IRBuilder<> IRB(Next);
							Module *M = F.getParent();
    					auto Int64Ty = IRB.getInt64Ty();
    					auto Int32Ty = IRB.getInt32Ty();
							auto Fn = M->getOrInsertFunction("mycast", Next->getType(), IRB.getInt8PtrTy(), Int64Ty, Int32Ty);
							auto CastCall = IRB.CreateCall(Fn, {CI, ConstantInt::get(Int64Ty, bitmap), ConstantInt::get(Int32Ty, ObjSz)});
							Next->replaceAllUsesWith(CastCall);
							assert(Next->use_empty());
							Next->eraseFromParent();
						}
					}
				}
			}
		}

    return false;
  }
}; // end of struct TypeAssigner
}  // end of anonymous namespace

char TypeAssigner::ID = 0;
static RegisterPass<TypeAssigner> X("typeassigner", "Type assigner pass",
                                 false /* Only looks at CFG */,
                                 false /* Analysis Pass */);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder,
       legacy::PassManagerBase &PM) { PM.add(new TypeAssigner()); });
