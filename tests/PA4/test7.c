#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

struct List {
	int *arr;
	struct List *next;
};

void __attribute__((noinline)) bar(int *arr, int offset) {
	arr[offset] = 0;
}

void __attribute__((noinline)) foo(struct List *node, int offset) {
	int *arr = node->arr;
	arr[offset] = 20;
	bar(&arr[offset+8], offset);
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("Usage:: <size> <offset>\n");
		return 0;
	}
	int size = readArgv(argv, 1);
	int offset = readArgv(argv, 2);
	int a[size];
	struct List node[size];
	memset(node, 0, size * sizeof(struct List));
	node[offset].arr = &a[offset+10];
	int i = rand() % size;
	if (node[i].arr) {
		return node[0].arr[0];
	}
	return 0;
}
