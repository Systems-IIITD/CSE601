#include <stdio.h>
#include "support.h"

/*
 * EXPECTED CHECKS
 * needed check before:   %arrayidx1 = getelementptr inbounds i32, i32* %3, i64 0
 * needed check before:   %arrayidx4 = getelementptr inbounds i32, i32* %8, i64 0
 * needed check before:   %arrayidx5 = getelementptr inbounds i32, i32* %9, i64 0
 */

int *gvar = NULL;

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
		ptr = gvar;
		ptr[0] = 100;
	}
	ptr[0] = 100;
}

int main()
{
	foo(NULL);
	return 0;
}
