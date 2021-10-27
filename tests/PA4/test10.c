#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

struct A {
	int *fld1;
	unsigned long long fld2;
	int *fld3;
	unsigned long long fld4;
	int *fld5;
	int *fld6;
};

void __attribute__((noinline)) foo(struct A *node, int offset) {
	char *arr = (char*)node;
	*(int*)(&arr[offset]) = 0;
}

int main(int argc, char *argv[])
{
	struct A *a = (struct A*)mymalloc(4 * sizeof(struct A));
	if (argc != 2) {
		printf("usage: <offset>\n");
		return 0;
	}
	int offset = readArgv(argv, 1);
	a[2].fld1 = mymalloc(4);
	a[2].fld3 = mymalloc(4);
	a[2].fld5 = mymalloc(4);
	a[2].fld6 = mymalloc(4);
	foo(a, offset);
	return 0;
}
