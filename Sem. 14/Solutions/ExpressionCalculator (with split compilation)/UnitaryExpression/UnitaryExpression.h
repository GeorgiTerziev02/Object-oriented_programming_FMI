#pragma once

#include "../BooleanExpression/BooleanExpression.h"

class UnitaryExpression : public BooleanExpression {
private:
    char _operand;
    BooleanExpression *_expression;

    void copyFrom(const UnitaryExpression &other);
    void moveFrom(UnitaryExpression &&other);
    void free();

public:
    // Needs Big6 if not inside class of ExpressionCalculator
    UnitaryExpression() = default;
    UnitaryExpression(const UnitaryExpression &other);
    UnitaryExpression(UnitaryExpression &&other) noexcept;
    UnitaryExpression &operator=(const UnitaryExpression &other);
    UnitaryExpression &operator=(UnitaryExpression &&other) noexcept;
    ~UnitaryExpression();

    UnitaryExpression(char operand, BooleanExpression *expression);

    BooleanExpression *clone() const override;

    bool evaluate(const BooleanInterpretation &interpretation) const override;

};