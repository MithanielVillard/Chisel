#include <iostream>
#include <ctd/Allocator.h>
#include <ctd/String.h>

int main(int argc, char** argv) {
	ctd::String s("Bonjour le monde !");
	ctd::String c('c');
	
	std::cout << s.Uncapitalized()[0] << "\n";
	std::cout << "test\n";
	std::cout << c;

	ctd::Allocator<float> testAlloc;
	float* ptr = testAlloc.Allocate(1);
	*ptr = 42;

	std::cout << *ptr;

	return 0;
}
