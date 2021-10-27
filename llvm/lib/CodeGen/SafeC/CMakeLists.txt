add_llvm_library ( LLVMCSE301 MODULE
	ArrayChecks.cpp
	NullChecks.cpp
	TypeAssigner.cpp
	TypeChecker.cpp
	MemSafe.cpp
	
  DEPENDS
  intrinsics_gen

	PLUGIN_TOOL
	opt
	)
