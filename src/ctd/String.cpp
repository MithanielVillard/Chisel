#include "ctd/String.h"
#include "types.h"
#include "utils/Utils.h"
#include <cstring>
#include <ostream>

namespace ctd 
{
	String::String(char const* str)
	{
		while (str[m_lenght]) m_lenght++;
		m_pData = new char[m_lenght];
		memcpy(m_pData, str, m_lenght * sizeof(char));
	}

	String::String(const char c)
	{
		m_lenght = 1;
		m_pData = new char[1];
		m_pData[0] = c;
	}

	String::String(String const& other)
	{
		m_lenght = other.m_lenght;
		m_pData = new char[m_lenght];
		memcpy(m_pData, other.m_pData, m_lenght * sizeof(char));
	}

	String::String(String&& other) noexcept
	{
		m_lenght = other.m_lenght;
		other.m_lenght = 0;
		m_pData = other.m_pData;
		other.m_pData = nullptr;
	}

	String& String::operator=(String const& other)
	{
		if (&other == this) return *this;

		m_lenght = other.m_lenght;
		m_pData = new char[m_lenght];
		memcpy(m_pData, other.m_pData, m_lenght * sizeof(char));
		return *this;
	}

	String& String::operator=(String&& other) noexcept
	{
		if (&other == this) return *this;

		m_lenght = other.m_lenght;
		other.m_lenght = 0;
		m_pData = other.m_pData;
		other.m_pData = nullptr;
		return *this;
	}

	String::~String() { delete[] m_pData; }

	String String::Capitalized()
	{
		if (IsAlpha(m_pData[0]) == false || IsUpperCase(m_pData[0]) == true)
			return *this;

		String result = *this;
		result.m_pData[0] -= 32;
		return result;
	}

	String String::Uncapitalized()
	{
		if (IsAlpha(m_pData[0]) == false || IsLowerCase(m_pData[0]) == true)
			return *this;

		String result = *this;
		result.m_pData[0] += 32;
		return result;
	}

	size_type String::Lenght() { return m_lenght; }
	char* String::Data() { return m_pData; }
	const char* String::CStr() { return m_pData; }
	char String::At(size_type pos) { return m_pData[pos]; }

	char String::operator[](size_type index)
	{
		return At(index);
	}

	String String::operator+(String const& right)
	{
		String result = *this;
		result += right;
		return result;
	}

	String String::operator+(const char right)
	{
		String result = *this;
		result += right;
		return  result;
	}

	void String::operator+=(String const& right)
	{
		size_type newLenght = m_lenght + right.m_lenght;
		m_pData = static_cast<char*>(realloc(m_pData, newLenght * sizeof(char)));
		memcpy(m_pData + m_lenght, right.m_pData, right.m_lenght);
		m_lenght = newLenght;
	}

	void String::operator+=(const char right)
	{
		size_type newLenght = m_lenght + 1;
		m_pData = static_cast<char*>(realloc(m_pData, newLenght * sizeof(char)));
		m_pData[newLenght - 1] = right;
		m_lenght = newLenght;
	}

	std::ostream& operator<<(std::ostream& out, String const& right)
	{
		out << right.m_pData;
		return out;
	}

}
