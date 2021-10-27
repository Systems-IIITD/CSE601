#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

struct List {
	int *arr;
	struct List *next;
};

struct List node;

void __attribute__((noinline)) bar(int *arr, int offset) {
	arr[offset] = 0;
}

int * __attribute__((noinline)) allocate_a(int size, int offset) {
	int *arr = mymalloc(size);
	return arr + offset;
}

void __attribute__((noinline)) foo(int *arr, int offset) {
	arr[offset] = 20;
	bar(&arr[offset+8], offset);
}

int main(int argc, const char *argv[])
{
	if (argc != 3) {
		printf("Usage:: <size> <offset>\n");
		return 0;
	}
	int size = readArgv(argv, 1) * sizeof(int);
	int offset = readArgv(argv, 2);
	int *a = allocate_a(size, offset);
	node.arr = a+1;
	foo(a+1, offset);
	return 0;
}
