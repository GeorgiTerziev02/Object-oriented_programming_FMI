#include "Label.h"

Label::Label() : Form(FormType::Label)
{
	labelText = nullptr;
}

void Label::print() const
{
	std::cout << "Label";
}

Form* Label::clone() const
{
	return new Label(*this);
}

void Label::setDataDialog(MyString labelText) 
{
	this->labelText = std::move(labelText);
}
