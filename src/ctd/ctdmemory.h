#ifndef CTDMEMORY_H
#define CTDMEMORY_H

#include "types.h"

void* ctd_internal_memccpy(void* destination, void const* source, char ch, size_type maxSize);
void* ctd_internal_memchr(void const* memoryBlock, char searchedChar, size_type size);
int32 ctd_internal_memcmp(void const* ptr1, void const* ptr2, size_type size);
void* ctd_internal_memcpy(void* destination, void const* source, size_type size);
void* ctd_internal_memmove(void* destination, void const* source, size_type size);
void* ctd_internal_memset(void* ptr, char value, size_type count);

#endif // !CTDMEMORY_H
