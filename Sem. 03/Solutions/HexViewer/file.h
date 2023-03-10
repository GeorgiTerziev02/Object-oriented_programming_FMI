#pragma once

#include "constants.h"

struct File {
	unsigned int size = 0;
	char name[FILE_NAME_SIZE];
	char data[FILE_SIZE];
};