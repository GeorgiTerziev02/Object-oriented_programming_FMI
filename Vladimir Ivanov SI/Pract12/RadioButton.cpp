#include "RadioButton.h"

RadioButton::RadioButton() : Form(FormType::RadioButton)
{
	optionsCount = 0;
	radioButtonsCheck = new bool[optionsCount] { false };
}

void RadioButton::print() const
{
	std::cout << "RadioButton" << std::endl;
}

Form* RadioButton::clone() const
{
	return new RadioButton(*this);
}

void RadioButton::setDataDialog(unsigned short index)
{
	if (index <= optionsCount)
	{
		return;
	}

	radioButtonsCheck[index] = true;
}

void RadioButton::setOptions(unsigned short optionsCount)
{
	if (this->optionsCount > 0)
	{
		return;
	}

	delete[] radioButtonsCheck;
	radioButtonsCheck = nullptr;

	this->optionsCount = optionsCount;
	radioButtonsCheck = new bool[optionsCount] { false }; 
}

RadioButton::~RadioButton()
{
	delete[] radioButtonsCheck;
}
