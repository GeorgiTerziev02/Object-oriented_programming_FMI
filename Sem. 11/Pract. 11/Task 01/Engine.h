#pragma once
#include "CarPart.h"

enum class EngineType { gasoline, diesel, electric, no_engine };

class Engine: public CarPart
{
	EngineType type;

public:
	Engine();
	Engine(unsigned int id, const MyString& manufacturer, const MyString& desc, EngineType type);
};