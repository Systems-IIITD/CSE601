CLANG=../../build/bin/clang
OPT=../../build/bin/opt
LLC=../../build/bin/llc
DIS=../../build/bin/llvm-dis
SLIB=../../build/lib/LLVMCSE301.so
SAFEGC=../../support/SafeGC

SRCS=$(filter-out support.c,$(wildcard *.c))
TARGETS=$(patsubst %.c,%,$(SRCS))

default: $(TARGETS)

dummy:
	touch dummy
	make -C $(SAFEGC)

% : %.c dummy
	$(CLANG) -I$(SAFEGC) -c -emit-llvm $<
	$(DIS) $*.bc
	$(OPT) -load $(SLIB) -f -typeassigner -o $*.bc < $*.bc
	$(OPT) -load $(SLIB) -f -typechecker -o $*.bc < $*.bc
	$(OPT) -load $(SLIB) -f -arraycheck -o $*.bc < $*.bc
	-$(DIS) -o $*_opt.ll $*.bc
	-$(LLC) $*.bc -o $*.s
	-$(CLANG) -O3 -L$(SAFEGC) -Wl,-rpath=$(SAFEGC) -o $@ $*.s -lmemory

clean:
	rm -f *.bc *.s *.ll $(TARGETS) *.o dummy
