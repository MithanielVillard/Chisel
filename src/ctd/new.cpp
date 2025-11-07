#include "ctd/new.h"
#include "ctd/Exception.h"
#include "ctd/ctdlib.h"


void* operator new(size_type size)
{
	void* ptr = ctd::malloc(size);
	if (ptr) 
		return ptr;
	else 
		throw ctd::BadAlloc{};
}
