#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "memory.h"
#include "support.h"

void checkTypeInv(void *Src, unsigned long long DstType)
{
}

void checkSizeInv(void *Dst, unsigned DstSize)
{
	unsigned DstOrigSize = GetSize(Dst);

	if (DstOrigSize < DstSize)
	{
		printf("Invalid obj size: min_required:%x current:%x\n", 
			(unsigned)DstSize, DstOrigSize);
		exit(0);
	}
}

void checkSizeAndTypeInv(void *Src, unsigned long long DstType, unsigned DstSize)
{
	checkTypeInv(Src, DstType);
	checkSizeInv(Src, DstSize);
}

void* mycast(void *Ptr, unsigned long long Bitmap, unsigned Size)
{
	checkSizeInv(Ptr, Size);
	SetType(Ptr, Bitmap);
	return Ptr;
}
