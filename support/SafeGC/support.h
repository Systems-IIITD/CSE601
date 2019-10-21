#ifndef __SUPPORT_H
#define __SUPPORT_H_

#include <stddef.h>

void checkSizeInv(void *Dst, unsigned DstSize);
void checkTypeAndSizeInv(void *Src, unsigned long long DstType, unsigned DstSize);
void checkTypeInv(void *Src, unsigned long long DstType);
void* mycast(void *Ptr, unsigned long long Bitmap, unsigned Size);

#endif
