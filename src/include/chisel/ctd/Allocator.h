#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "types.h"
#include "ctd/ctdlib.h"
#include "ctd/Exception.h"
#include "ctd/new.h"

namespace ctd 
{
	template<typename T>
	class Allocator
	{
	public:
		constexpr Allocator() = default;
		constexpr Allocator(Allocator const& other) noexcept;
		constexpr ~Allocator() = default;
	
		T* Allocate(size_type n);
		void Deallocate(T* ptr, size_type n);
	};	

	template<typename T>
	T* Allocator<T>::Allocate(size_type n)
	{
		if (n > INT64_MAX / sizeof(T)) throw BadAlloc{};
		
		void* ptr = ::operator new(n * sizeof(T));
		if (ptr) 
			return static_cast<T*>(ptr);
		else 
			throw BadAlloc{};
	}

	template<typename T>
	void Allocator<T>::Deallocate(T* ptr, size_type n)
	{
		free(ptr);
	}
}
#endif // !ALLOCATOR_H
