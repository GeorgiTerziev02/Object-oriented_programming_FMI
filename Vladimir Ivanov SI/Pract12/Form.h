#pragma once

enum class FormType {
	Label = 0,
	CheckBox = 1,
	RadioButton = 2
};

class Form {
public:
	Form(FormType type);
	FormType getType() const;

	virtual void print() const = 0;
	virtual Form* clone() const = 0;

	virtual ~Form() = default;

private:
	FormType type;
};