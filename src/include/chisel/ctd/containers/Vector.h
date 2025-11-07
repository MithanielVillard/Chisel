#ifndef VECTOR_H
#define VECTOR_H

#include "types.h"

namespace ctd 
{
	template <typename T>
	class Vector
	{
		public:
			Vector<T>() = default;

		private:
			T* m_pData = nullptr;
			size_type m_size = 0;
			size_type m_capacity = 0;
	};
}

#endif // !VECTOR_H
