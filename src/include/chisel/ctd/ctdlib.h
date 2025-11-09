#ifndef CTDLIB_H
#define CTDLIB_H

#include "types.h"
#include "ctdmemory.h"

//========= MACRO UTILS ==============

#if defined(__has_include)
		#define has_include(include) __has_include(include)
#endif

//========= MACRO CONSTANTS ===========


#undef EXIT_SUCCESS
#undef EXIT_FAILURE
#undef NULL
#undef RAND_MAX

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 0
#define NULL 		 nullptr
#define RAND_MAX	 32767

//========= MEMORY MANAGEMENT ==========

namespace ctd 
{
	inline void* malloc(size_type size) { return ::malloc(size); }
	//inline void* calloc( size_type elemCount, size_type elemSize) { return ::calloc(elemCount, elemSize); }
	//inline void* realloc(void* ptr, size_type size) { return ::realloc(ptr, size); }
	inline void free(void* ptr) { ::free(ptr);}
}

#endif // !CTDLIB_H
