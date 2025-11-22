#include "ctd/new.h"
#include "ctd/Exception.h"
#include "ctd/ctdlib.h"
//#include <iostream>


void* operator new(size_type size)
{
	void* ptr = ctd::malloc(size);
//	std::cout << "New operator called \n";
	if (ptr) 
		return ptr;
	else 
		throw ctd::BadAlloc{};
}
