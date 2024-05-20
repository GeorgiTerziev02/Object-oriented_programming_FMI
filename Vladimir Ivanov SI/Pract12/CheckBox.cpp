#include "CheckBox.h"

CheckBox::CheckBox() : Form(FormType::CheckBox)
{
	isOn = false;
}

void CheckBox::print() const
{
	std::cout << "CheckBox" << std::endl;
}

Form* CheckBox::clone() const
{
	return new CheckBox(*this);
}

void CheckBox::setDataDialog(bool isOn)
{
	if (this->isOn != isOn)
	{
		this->isOn = isOn;
	}
}

void CheckBox::changeText(MyString&& checkBoxText)
{
	this->checkBoxText = std::move(checkBoxText);
}
