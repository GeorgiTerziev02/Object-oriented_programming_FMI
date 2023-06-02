#pragma once

#include "../MyString/MyString.h"
#include "../StringView/StringView.h"

#include "../BooleanInterpretation/BooleanInterpretation.h"

#include "../BooleanExpression/BooleanExpression.h"

class ExpressionCalculator {
private:
    BooleanExpression *_expression;

    static BooleanExpression *parseExpression(const StringView &strView);

    bool checkAllVariations(bool expectedValue) const;

    void copyFrom(const ExpressionCalculator &other);
    void moveFrom(ExpressionCalculator &&other);
    void free();

public:
    // Big6 (mandatory)
    ExpressionCalculator() = default;
    ExpressionCalculator(const ExpressionCalculator &other);
    ExpressionCalculator(ExpressionCalculator &&other);
    ExpressionCalculator &operator=(const ExpressionCalculator &other);
    ExpressionCalculator &operator=(ExpressionCalculator &&other);
    ~ExpressionCalculator();

    ExpressionCalculator(const MyString &str);

    bool isTautology() const;
    bool isContradiction() const;

};
