#include "Util.h"
#include <cstring>
#pragma warning (disable: 4996)

void Util::copyDynamicCharArray(char*& dest, const char* source) {
	dest = new char[strlen(source) + 1];
	strcpy(dest, source);
}