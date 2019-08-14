CLANG=../build/bin/clang
DIS=../build/bin/llvm-dis

default: array.ll

array.ll: array.c
	$(CLANG) -c -emit-llvm array.c
	$(DIS) array.bc

clean:
	rm -f array.ll array.bc
