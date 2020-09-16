#include <stdio.h>
#include "support.h"

void foo (int *arr)
{
	int *ptr = mymalloc(4);

	ptr[0] = 100;
label:
	if (ptr == NULL) {
		ptr[0] = 100;
	}
	else {
		ptr[0] = 100;
	}
	ptr[0] = 100;
	ptr = arr;
	goto label;
}

int main()
{
	foo(NULL);
	return 0;
}
