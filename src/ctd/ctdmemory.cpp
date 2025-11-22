#include "ctdmemory.h"
#include "types.h"

void* ctd_internal_memccpy(void* destination, void const* source, char ch, size_type maxSize)
{
	char const* srcPtr = reinterpret_cast<char const*>(source);
	char* destPtr = reinterpret_cast<char*>(destination);

	for (size_type i = 0; i < maxSize; i++)
	{
		bool equal = srcPtr[i] == ch;
		destPtr[i] = srcPtr[i];

		if (equal) return const_cast<void*>(reinterpret_cast<void const*>(&srcPtr[i] + 1)); 
	}
	return nullptr;
}

void* ctd_internal_memchr(void const* memoryBlock, char searchedChar, size_type size)
{
	char const* ptr = reinterpret_cast<char const*>(memoryBlock);
	for (size_type i = 0; i < size; i++)
	{
		if (ptr[i] == searchedChar)
			return const_cast<void*>(reinterpret_cast<void const*>(&ptr[i]));
	}
	return nullptr;
}

int32 ctd_internal_memcmp(void const* ptr1, void const* ptr2, size_type size)
{
	byte const* _ptr1 = reinterpret_cast<byte const*>(ptr1);
	byte const* _ptr2 = reinterpret_cast<byte const*>(ptr2);

	for (size_type i = 0; i < size; i++)
	{
		if (_ptr1[i] > _ptr2[i]) return 1;
		if (_ptr1[i] < _ptr2[i]) return -1;
	}

	return 0;
}

void* ctd_internal_memcpy(void* destination, void const* source, size_type size)
{
	for (size_type i = 0; i < size; i++)
	{
		reinterpret_cast<byte*>(destination)[i] = reinterpret_cast<byte const*>(source)[i];
	}
	return destination;
}

void* ctd_internal_memmove(void* destination, void const* source, size_type size)
{
	byte const* srcPtr = reinterpret_cast<byte const*>(source);
	byte* dstPtr = reinterpret_cast<byte*>(destination);

	//beginning of dest overlaps
	if (srcPtr + size >= dstPtr)
	{
		for (size_type i = 0; i < size; i++)
		{
			dstPtr[i] = srcPtr[size - 1 - i];
		}
		return destination;
	}

	//end of dest overlaps
	if (dstPtr + size >= srcPtr)
	{
		for (size_type i = 0; i < size; i++)
		{
			dstPtr[i] = srcPtr[0];
		}
		return destination;
	}

	ctd_internal_memcpy(destination, source, size);
	return destination;
}

void* ctd_internal_memset(void* ptr, char value, size_type count)
{
	for (size_type i = 0; i < value; i++)
	{
		reinterpret_cast<byte*>(ptr)[i] = value;
	}
	return ptr;
}
