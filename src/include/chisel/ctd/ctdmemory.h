#ifndef CTDMEMORY_H
#define CTDMEMORY_H

#include <types.h>
#include <libc.h>

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

size_type align(size_t size, size_t alignment);

void* malloc(size_type size);
void free(void* ptr);


#endif // !MEMORY_H
