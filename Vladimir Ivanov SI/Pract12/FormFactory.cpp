#include "FormFactory.h"
#include "Label.h"
#include "CheckBox.h"
#include "RadioButton.h"

Form* formFactory(FormType type)
{
	switch (type)
	{
	case FormType::Label: return new Label();
		break;
	case FormType::CheckBox: return new CheckBox();
		break;
	case FormType::RadioButton: return new RadioButton();
		break;
	}

	throw std::invalid_argument("Invalid animal type");
}
