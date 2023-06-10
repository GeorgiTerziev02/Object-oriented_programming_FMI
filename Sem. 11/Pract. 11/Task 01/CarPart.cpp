#include "CarPart.h"

CarPart::CarPart(unsigned int id, const MyString& manufacturer, const MyString& description)
	:id(id), manufacturer(manufacturer), description(description) {}

CarPart::~CarPart() {}