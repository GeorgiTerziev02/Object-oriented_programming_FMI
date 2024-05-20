#pragma once
#include "Form.h"
#include "MyString.h"

class CheckBox : public Form {
public:
	CheckBox();
	void print() const override;
	Form* clone() const override;
	void setDataDialog(bool isOn);
	void changeText(MyString&& checkBoxText);

private:
	bool isOn;
	MyString checkBoxText;
};