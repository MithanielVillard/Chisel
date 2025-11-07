#ifndef STRING_H
#define STRING_H

#include "types.h"
#include "ctd/ctdlib.h"

#if has_include(<ostream>)
#include <ostream>
#endif

namespace ctd 
{
	class String
	{
		public:
			String() = default;
			String(const char* str);
			String(const char c);
			String(String const& other);
			String(String&& other) noexcept;

			String& operator=(String const& other);
			String& operator=(String&& other) noexcept;
			~String();
			
			String Capitalized();
			String Uncapitalized();

			size_type Lenght();
			char* Data();
			char At(size_type pos);
			const char* CStr();

			char operator[](size_type index);
			String operator+(String const& right);
			String operator+(const char right);
			void operator+=(String const& right);
			void operator+=(char const right);

			#if has_include(<ostream>) 
			friend std::ostream& operator<<(std::ostream& out, const String& right);
			#endif

		private:
			char* m_pData = nullptr;
			size_type m_lenght = 0;
	};
}

#endif // !STRING_H
