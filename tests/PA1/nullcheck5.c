#include <stdio.h>
#include "support.h"

/*
 * EXPECTED CHECKS
 * needed check before:   %arrayidx1 = getelementptr inbounds i32, i32* %3, i64 0
 * needed check before:   %arrayidx2 = getelementptr inbounds i32, i32* %4, i64 0
 * needed check before:   %arrayidx3 = getelementptr inbounds i32, i32* %5, i64 0
 */

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
