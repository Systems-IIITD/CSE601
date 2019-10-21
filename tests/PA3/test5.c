#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

typedef unsigned long long u64;

struct A
{
	u64 a;
};

struct B
{
	u64 a;
	u64 b;
};

void foo()
{
	struct A *v1 = (struct A*)mymalloc(sizeof(struct A));
	struct B *v2 = (struct B*)v1;
}

int main()
{
	foo();
	return 0;
}
