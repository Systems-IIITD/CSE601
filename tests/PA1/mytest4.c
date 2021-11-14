#include <stdio.h>
#include "support.h"

int main(int argc, char const *argv[])
{
	int input;
	scanf("%d",&input);
	int * ptr;
	if (input>0)
	{
		ptr = mymalloc(4);
	}else
	{
		ptr = NULL;
	}
	*ptr = 6;
	return 0;
}
