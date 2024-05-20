#pragma once
#include "MyString.h"
#include "Form.h"

class RadioButton : public Form {
public:
	RadioButton();
	void print() const override;
	Form* clone() const override;
	void setDataDialog(unsigned short index);
	void setOptions(unsigned short optionsCount);
	~RadioButton();

private:
	unsigned short optionsCount;
	bool* radioButtonsCheck = nullptr;
};