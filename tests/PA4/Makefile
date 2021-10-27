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
	$(CLANG) -I$(SAFEGC) -O3 -c -emit-llvm $<
	$(DIS) $*.bc
	$(OPT) -load $(SLIB) -f -memsafe -o $*.bc < $*.bc
	$(OPT) -load $(SLIB) -f -typeassigner -o $*.bc < $*.bc
	$(DIS) -o $*_opt.ll $*.bc
	$(LLC) $*.bc -o $*.s
	$(CLANG) -g -O3 -L$(SAFEGC) -Wl,-rpath=$(SAFEGC) -o $@ $*.s -lmemory

run1:
	./test1 20 2
	./test1 20 5
	./test1 20 20
	./test1 20 19
	./test1 20 6

run:
	echo "running test1"
	./test1 20 2
	./test1 20 5
	./test1 20 20
	./test1 20 19
	./test1 20 6
	echo "running test1"
	./test2 20 2
	./test2 20 5
	./test2 20 19
	./test2 20 6
	echo "running test3"
	./test3 20 2
	./test3 20 5
	./test3 20 20
	./test3 20 19
	./test3 20 6
	echo "running test4"
	./test4 20 2
	./test4 20 5
	./test4 20 20
	./test4 20 19
	./test4 20 6
	echo "running test5"
	./test5 0
	./test5 8
	./test5 13
	./test5 28
	./test5 29
	echo "running test6"
	./test6 0
	./test6 8
	./test6 13
	./test6 28
	./test6 29
	echo "running test7"
	./test7 20 9
	./test7 20 10
	echo "running test8"
	./test8 20 4
	./test8 20 5
	./test8 20 14
	./test8 20 15
	echo "running test9"
	./test9 0
	./test9 8
	./test9 13
	./test9 28
	./test9 29
	echo "running test10"
	./test10 8
	./test10 16
	./test10 21
	./test10 36
	./test10 27


clean:
	rm -f *.bc *.s *.ll $(TARGETS) *.o dummy
