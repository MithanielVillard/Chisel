#ifndef UTILS_H
#define UTILS_H

namespace ctd 
{
	inline bool IsAlpha(char c)
	{
		return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); 
	}

	inline bool IsUpperCase(char c)
	{
		return (c >= 'A' && c <= 'Z');
	}

	inline bool IsLowerCase(char c)
	{
		return (c >= 'a' && c <= 'z');
	}

	inline bool IsNumeric(char c)
	{
		return (c >= '0' && c <= '9');
	}

}

#endif // !UTILS_H
