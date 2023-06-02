#pragma once

#include "../BooleanExpression/BooleanExpression.h"

class BinaryExpression : public BooleanExpression {
private:
    char _operand;
    BooleanExpression *_left;
    BooleanExpression *_right;

    void copyFrom(const BinaryExpression &other);
    void moveFrom(BinaryExpression &&other);
    void free();

public:
    // Needs Big6 if not inside class of ExpressionCalculator
    BinaryExpression() = default;
    BinaryExpression(const BinaryExpression &other);
    BinaryExpression(BinaryExpression &&other) noexcept;
    BinaryExpression &operator=(const BinaryExpression &other);
    BinaryExpression &operator=(BinaryExpression &&other) noexcept;
    ~BinaryExpression();

    BinaryExpression(char operand, BooleanExpression *left, BooleanExpression *right);

    BooleanExpression *clone() const;
    bool evaluate(const BooleanInterpretation &interpretation) const override;

};
