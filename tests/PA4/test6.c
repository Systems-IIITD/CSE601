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

int main(int argc, const char *argv[])
{
	struct A a;
	if (argc != 2) {
		printf("usage: <offset>\n");
		return 0;
	}
	int offset = readArgv(argv, 1);
	a.fld1 = mymalloc(4);
	a.fld3 = mymalloc(4);
	a.fld5 = mymalloc(4);
	a.fld6 = mymalloc(4);
	char *arr = (char*)&a.fld2;
	arr[offset] = 0;
	return a.fld1 == a.fld5;
}
