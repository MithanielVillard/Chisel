#include "types.h"
#include <cstdlib>
#include <iostream>
#include <ctd/Allocator.h>
#include <ctd/String.h>
#include <ctd/ctdlib.h>

int main(int argc, char** argv) {
	//ctd::String s("Bonjour le monde !");
	//ctd::String c('c');

	//std::cout << s.Uncapitalized()[0] << "\n";
	//std::cout << "test\n";
	//std::cout << c;

	//ctd::Allocator<float> testAlloc;
	//float* ptr = testAlloc.Allocate(1);
	//*ptr = 42;

	//std::cout << *ptr;

	//testAlloc.Deallocate(ptr, 1);

	int* test = (int*) malloc(sizeof(int));
	*test = 42;
	free(test);


	size_type* test2 = (size_type*) malloc(sizeof(size_type));
	*test2 = 78880;
	std::cout << *test2;
	free(test2);

	//size_type* st = (size_type*) malloc(sizeof(size_type));
	//*st = 702000;

	return 0;
}
