#include "Variable.h"

Variable::Variable(char ch) : _ch(ch) {
    _variablesCount = 1;
    _variables[ch - 'A'] = true;
}

BooleanExpression *Variable::clone() const {
    return new Variable(_ch);
}

bool Variable::evaluate(const BooleanInterpretation &interpretation) const {
    return interpretation.getVar(_ch);
}
