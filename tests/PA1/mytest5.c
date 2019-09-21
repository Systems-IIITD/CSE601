#include <stdio.h>
#include "support.h"

int main(int argc, char const *argv[])
{
	int * p;	
	int addr;
	scanf("%d",&addr);
	p = (int *)addr;
	*p = 5;
	return 0;
}
