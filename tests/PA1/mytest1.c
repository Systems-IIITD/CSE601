#include <stdio.h>
#include "support.h"

int main(int argc, char const *argv[])
{
	int n = 10;
	int m = 5;
	int o = 6;
	int *** arr = mymalloc(m*sizeof(int **));
	for (int i=0;i<m;i++)
	{
		if (i!=4)
		{
			arr[i] = mymalloc(n*sizeof(int *));
		}
	}
	for (int i=0; i<m; i++)
	{
		for (int j=0;j<n;j++)
		{
			if (j != 3)
			{
				arr[i][j] = mymalloc(o*sizeof(int));
			}
		}
	}
	int sum = 0;
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<n ; j++)
		{
			int * curr = arr[i][j];
			for (int k=0;k<o;k++)
			{
				curr[k] = i+j-o;
			}
		
		}
	}
	return 0;
}
