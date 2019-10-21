#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stddef.h>

void *mymalloc(size_t Size);
void printMemoryStats();
void runGC();
unsigned GetSize(void *Obj);
unsigned long long GetType(void *Obj);
void SetType(void *Obj, unsigned long long Type);

#endif
