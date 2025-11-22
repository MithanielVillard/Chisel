#include "ctdmalloc.h"
#include "types.h"

#include "ctd/Exception.h"

#include <sys/mman.h>
#include <unistd.h>

size_type align(size_type size, size_type alignment)
{
    return (size + alignment - 1) & ~(alignment - 1);
}

Heap* CreateNewHeap()
{
	void* heap_ptr = (Block*) mmap(nullptr, getpagesize(), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
	if (heap_ptr == nullptr) throw ctd::BadAlloc {};

	Heap* heap_header = (Heap*) heap_ptr;
	heap_header->availSize = getpagesize() - sizeof(Heap);
	heap_header->pHeadBlock = (Block*) heap_header + 1;

	heap_header->pHeadBlock->blockSize = heap_header->availSize;
	heap_header->pHeadBlock->occupied = false;

	return (Heap*) heap_ptr;
}

Heap* FindAvaillableHeap(size_type size)
{
	Heap* start_ptr = headHeapPtr;
	while (start_ptr) 
	{
		if (start_ptr->availSize >= size)
			return start_ptr;
		start_ptr = start_ptr->pNextHeap;
	}

	start_ptr->pNextHeap = CreateNewHeap();
	return start_ptr;
}

Block* FindAvaillableBlock(Heap* heap, size_type size)
{
	Block* start_ptr = heap->pHeadBlock;
	while (start_ptr) 
	{
		if (start_ptr->blockSize >= size && start_ptr->occupied == false)
			return start_ptr;
		start_ptr = start_ptr->pNextBlock;
	}

	return nullptr;
}

void* ctd_internal_malloc(size_type size)
{
	if (size <= 0 || size >= getpagesize()) throw ctd::BadAlloc {};

	//First call to malloc we create the heap
	if (headHeapPtr == nullptr)
		headHeapPtr = CreateNewHeap();

	Heap* heap = FindAvaillableHeap(size);
	Block* block = FindAvaillableBlock(heap, size);

	block->occupied = true;
	//Align size of malloc to 16 byte
	block->blockSize = align(size, 16);
	block->pBlockHeap = heap;

	if (block->pNextBlock == nullptr)
	{
		block->pNextBlock = (Block*)((char*)block + 1) + block->blockSize;
		block->pNextBlock->occupied = false;
		heap->availSize -= block->blockSize;
		block->pNextBlock->blockSize = heap->availSize;
	}

	return block + 1;
}

void* ctd_internal_realloc(void* ptr, size_type newSize)
{
	//TODO realloc
	return ptr;
}

void ctd_internal_free(void* ptr)
{
	if (ptr == nullptr) return;
	Block* b = (Block*)((char*)ptr - sizeof(Block));
	b->occupied = false;

	//Merge if next block is empty
	if (b->pNextBlock->occupied == false)
	{
		//std::cout << "Merged two blocks \n";
		b->blockSize += b->pNextBlock->blockSize;
		//Next block is now the next block of the block being merged
		b->pNextBlock = b->pNextBlock->pNextBlock;
	}

	if (b->pBlockHeap->availSize < b->blockSize)
		b->pBlockHeap->availSize = b->blockSize;
}
