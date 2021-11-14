#include <stdio.h>
#include "support.h"

int main(int argc, char const *argv[])
{
	FILE * fptr = fopen("fdshg","r");	
	printf("%d\n",fptr->_flags);
	return 0;
}
