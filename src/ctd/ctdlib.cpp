#include "ctdmalloc.h"
#include "ctd/ctdlib.h"

namespace ctd 
{
	void* malloc(size_type size) { return ::ctd_internal_malloc(size); }
	//inline void* calloc( size_type elemCount, size_type elemSize) { return ::calloc(elemCount, elemSize); }
	void* realloc(void* ptr, size_type size) { return ::ctd_internal_realloc(ptr, size); }
	void free(void* ptr) { ::ctd_internal_free(ptr);}
}
