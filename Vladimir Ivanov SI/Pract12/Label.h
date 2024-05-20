#pragma once
#include "Form.h"
#include "MyString.h"

class Label : public Form {
public:
	Label();
	void print() const override;
	Form* clone() const override;
	void setDataDialog(MyString labelText);

private:
	MyString labelText;
};