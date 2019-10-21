#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

typedef unsigned long long u64;

struct A {
	char a1;
	char a2;
	char a3;
	char a4;
	char a5;
	u64 b;
} __attribute__((packed));

int main()
{
	int *a = (int*)mymalloc(sizeof(int) * 6);
	struct A *obj = (struct A*)a;
	obj[1].a5 = 100;
	return 0;
}
