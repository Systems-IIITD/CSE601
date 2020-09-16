#include <stdio.h>
#include <stdlib.h>
#include "support.h"

int *bar(int size)
{
	return NULL;
}

void foo (int *arr)
{
	int *ptr = mymalloc(4);

	ptr[0] = 100;
	ptr = arr;
	ptr[0] = 100;
	if (ptr == NULL) {
		ptr = mymalloc(4);
		ptr[0] = 100;
	}
	else {
		ptr = bar(4);
		ptr[0] = 100;
	}
	ptr[0] = 100;
}

int main()
{
	foo(NULL);
	return 0;
}
