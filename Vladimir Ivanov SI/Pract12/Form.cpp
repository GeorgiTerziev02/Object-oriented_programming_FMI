#include "Form.h"

Form::Form(FormType type)
{
	this->type = type;
}

FormType Form::getType() const
{
	return type;
}
