#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

struct A {
	unsigned long long fld1;
	unsigned long long fld2;
	unsigned long long fld3;
	unsigned long long fld4;
	unsigned long long fld5;
	unsigned long long fld6;
};

void __attribute__((noinline)) foo(struct A *node, int offset) {
	char *arr = (char*)node;
	arr[offset] = 0;
}

int main(int argc, char *argv[])
{
	struct A a;
	if (argc != 2) {
		printf("usage: <offset>\n");
		return 0;
	}
	int offset = readArgv(argv, 1);
	a.fld1 = (size_t)mymalloc(4);
	a.fld3 = (size_t)mymalloc(4);
	a.fld5 = (size_t)mymalloc(4);
	a.fld6 = (size_t)mymalloc(4);
	foo((struct A*)&a.fld2, offset);
	return 0;
}
