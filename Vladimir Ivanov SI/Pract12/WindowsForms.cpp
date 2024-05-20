#include "WindowsForms.h"
#include "Label.h"
#include "CheckBox.h"
#include "RadioButton.h"
#include "FormFactory.h"

WindowsForms::WindowsForms() : capacity(0), size(0)
{
	forms = new Form*[capacity];
}

WindowsForms::WindowsForms(Form**&& forms, const unsigned int capacity, unsigned int size) : capacity(capacity) , size(size), forms(forms)
{

}

WindowsForms::WindowsForms(const WindowsForms& other)
{
	copyFrom(other);
}

WindowsForms::WindowsForms(WindowsForms&& other) noexcept
{
	moveFrom(std::move(other));
}

WindowsForms& WindowsForms::operator=(const WindowsForms& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

WindowsForms& WindowsForms::operator=(WindowsForms&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

WindowsForms::~WindowsForms()
{
	free();
}

void WindowsForms::addForm(FormType type)
{
	if (size == capacity)
	{
		resize();
	}

	forms[size++] = formFactory(type);
}

void WindowsForms::copyFrom(const WindowsForms& other)
{
	this->size = other.size;

	this->capacity = other.capacity;

	this->forms = new Form*[other.capacity];
	for (unsigned int i = 0; i < other.size; i++)
	{
		this->forms[i] = other.forms[i]->clone();
	}
}

void WindowsForms::moveFrom(WindowsForms&& other)
{
	this->size = other.size;
	other.size = 0;

	this->capacity = other.capacity;
	other.capacity = 0;

	this->forms = other.forms;
	other.forms = nullptr;
}

void WindowsForms::resize()
{
	Form** newForms = new Form * [capacity *= 2];
	for (unsigned int i = 0; i < size; i++)
	{
		newForms[i] = forms[i];
	}
	delete[] forms;

	forms = newForms;
}

void WindowsForms::free()
{
	for (unsigned int i = 0; i < size; i++)
	{
		delete forms[i];
	}
	delete[] forms;

	size = 0;
	capacity = 0;
}
