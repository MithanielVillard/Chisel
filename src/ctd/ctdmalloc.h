#ifndef CTDMALLOC_H
#define CTDMALLOC_H

#include "types.h"

struct Heap;

struct Block
{
	size_type blockSize;
	bool occupied;
	Block* pNextBlock = nullptr;
	Heap* pBlockHeap = nullptr;
};

struct Heap
{
	Block* pHeadBlock;
	Heap* pNextHeap;
	size_type availSize;
};

inline Heap* headHeapPtr = nullptr;

Heap* CreateNewHeap();
Heap* FindAvaillableHeap(size_type size);
Block* FindAvaillableBlock(Heap* heap, size_type size);
Block* MergeTwoBlocks(Block* b1, Block* b2);

size_type align(size_type size, size_type alignment);

void* ctd_internal_malloc(size_type size);
void* ctd_internal_realloc(void* ptr, size_type newSize);
void ctd_internal_free(void* ptr);

#endif // !CTDMALLOC
