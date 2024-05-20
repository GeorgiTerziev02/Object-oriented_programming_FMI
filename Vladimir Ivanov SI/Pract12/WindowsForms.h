#pragma once
#include "Form.h"

class WindowsForms {
public:
	WindowsForms();
	WindowsForms(Form**&& forms, const unsigned int capacity, unsigned int size);
	WindowsForms(const WindowsForms& other);
	WindowsForms(WindowsForms&& other) noexcept;
	WindowsForms& operator=(const WindowsForms& other);
	WindowsForms& operator=(WindowsForms&& other) noexcept;
	~WindowsForms();

	void addForm(FormType type);

private:
	Form** forms = nullptr;
	unsigned int capacity;
	unsigned int size;

	void copyFrom(const WindowsForms& other);
	void moveFrom(WindowsForms&& other);
	void free();
	void resize();
};