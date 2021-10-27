#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stddef.h>

void *mymalloc(size_t Size);
void printMemoryStats();
void runGC();
unsigned GetSize(void *Obj);
unsigned long long GetType(void *Obj);
void SetType(void *Obj, unsigned long long Type);
void myfree(void *Ptr);
void* GetAlignedAddr(void *Addr, size_t Alignment);
int readArgv(const char *argv[], int idx);

#endif
