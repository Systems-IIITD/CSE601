#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

typedef unsigned long long u64;

struct A
{
	u64 a;
	u64 b;
	u64 *c;
};

struct B
{
	u64 a;
	u64 b;
	u64 *c;
	u64 d;
	u64 e;
	u64 *f;
};

void foo()
{
	struct B *v1 = (struct B*)mymalloc(sizeof(struct B) + 16);
	struct A *v2 = (struct A*)v1;
	v2[2].c = NULL;
}

int main()
{
	foo();
	return 0;
}
