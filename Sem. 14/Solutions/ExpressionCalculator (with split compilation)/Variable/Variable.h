#pragma once

#include "../BooleanExpression/BooleanExpression.h"

class Variable : public BooleanExpression {
private:
    char _ch;

public:
    Variable(char ch);

    BooleanExpression *clone() const override;

    bool evaluate(const BooleanInterpretation &interpretation) const override;

};
