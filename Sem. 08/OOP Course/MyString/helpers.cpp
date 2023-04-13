#include "helpers.h"
#include <iostream>

int strLen(const char* str)
{
	int size = 0;
	while (str[size] != '\0')
	{
		size++;
	}

	return size;
}

char* strCpy(char* destination, const char* source)
{
	char* ptr = destination;
	while (*source)
	{
		*destination++ = *source++;
	}
	*destination = '\0';
	return ptr;
}

int strCmp(const char* str1, const char* str2)
{
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return str1[i] - str2[i];
		}
		i++;
	}
	return 0;
}

char* strCat(char* dest, const char* src)
{
	char* p = dest;
	while (*p)
	{
		++p;
	}
	while (*src)
	{
		*p++ = *src++;
	}
	*p = '\0';
	return dest;
}

char* strStr(const char* str1, const char* str2)
{
	size_t substr_len = strLen(str2);
	for (size_t i = 0; str1[i] != '\0'; ++i)
	{
		bool match = true;
		for (size_t j = 0; j < substr_len; ++j)
		{
			if (str1[i + j] != str2[j])
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			return const_cast<char*>(str1 + i);
		}
	}
	return nullptr;
}