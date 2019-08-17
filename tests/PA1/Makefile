CLANG=../../build/bin/clang
OPT=../../build/bin/opt
LLC=../../build/bin/llc
DIS=../../build/bin/llvm-dis
SLIB=../../build/lib/LLVMCSE301.so

SRCS=$(filter-out support.c,$(wildcard *.c))
TARGETS=$(patsubst %.c,%,$(SRCS))

default: $(TARGETS)

% : %.c support.o
	$(CLANG) -c -emit-llvm $<
	$(DIS) $*.bc
	$(OPT) -load $(SLIB) -f -nullcheck -o $*.bc < $*.bc
	$(DIS) -o $*_opt.ll $*.bc
	$(LLC) $*.bc -o $*.s
	$(CLANG) support.o $*.s -o $@

support.o: support.c
	gcc -c support.c

clean:
	rm -f *.bc *.s *.ll $(TARGETS) *.o
