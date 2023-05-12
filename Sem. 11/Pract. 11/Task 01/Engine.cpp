#include "Engine.h"

Engine::Engine(unsigned int id, const MyString& manufacturer, const MyString& desc, EngineType type)
	: CarPart(id, manufacturer, desc), type(type) {}

Engine::Engine(): CarPart(0, "", ""), type(EngineType::no_engine) {}