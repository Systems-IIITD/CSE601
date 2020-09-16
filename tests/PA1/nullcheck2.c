#include <stdio.h>
#include "support.h"

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
		ptr = mymalloc(4);
		ptr[0] = 100;
	}
	ptr[0] = 100;
}

int main()
{
	foo(NULL);
	return 0;
}
