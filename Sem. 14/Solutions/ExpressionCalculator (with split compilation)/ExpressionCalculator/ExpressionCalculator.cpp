#include "ExpressionCalculator.h"

#include "../Variable/Variable.h"
#include "../UnitaryExpression/UnitaryExpression.h"
#include "../BinaryExpression/BinaryExpression.h"

namespace {
    bool isCharBinaryOperand(char ch) {
        return ch == AND || ch == OR || ch == IMP || ch == EQV;
    }
}

void ExpressionCalculator::copyFrom(const ExpressionCalculator &other) {
    _expression = other._expression->clone();
}

void ExpressionCalculator::moveFrom(ExpressionCalculator &&other) {
    _expression = other._expression;
    other._expression = nullptr;
}

void ExpressionCalculator::free() {
    delete _expression;
}

ExpressionCalculator::ExpressionCalculator(const ExpressionCalculator &other) {
    copyFrom(other);
}

ExpressionCalculator::ExpressionCalculator(ExpressionCalculator &&other) {
    moveFrom(std::move(other));
}

ExpressionCalculator &ExpressionCalculator::operator=(const ExpressionCalculator &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

ExpressionCalculator &ExpressionCalculator::operator=(ExpressionCalculator &&other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

ExpressionCalculator::~ExpressionCalculator() {
    free();
}

BooleanExpression *ExpressionCalculator::parseExpression(const StringView &strView) {
    if(strView.length() == 0)
        return nullptr;

    if(strView.length() == 1)
        return new Variable(strView[0]);

    StringView strWithoutBrackets = strView.substr(1, strView.length() - 2);

    size_t bracketsCount = 0;
    size_t strWithoutBracketsLength = strWithoutBrackets.length();
    for (size_t i = 0; i < strWithoutBracketsLength; ++i) {
        if (strWithoutBrackets[i] == NEG && bracketsCount == 0)
            return new UnitaryExpression(
                    NEG,
                    parseExpression(strWithoutBrackets.substr(i + 1, strWithoutBracketsLength - i - 1))
            );
        else if (isCharBinaryOperand(strWithoutBrackets[i]))
            return new BinaryExpression(
                    strWithoutBrackets[i],
                    parseExpression(strWithoutBrackets.substr(0, i)),
                    parseExpression(strWithoutBrackets.substr(i + 1, strWithoutBracketsLength - i - 1))
            );
        else if (strWithoutBrackets[i] == '(')
            ++bracketsCount;
        else if (strWithoutBrackets[i] == ')')
            --bracketsCount;
    }

    return nullptr;
}

ExpressionCalculator::ExpressionCalculator(const MyString &str) {
    _expression = parseExpression(str);
}

bool ExpressionCalculator::checkAllVariations(bool expectedValue) const {
    size_t variationsCount = 1 << _expression->_variablesCount;
    for (size_t i = 0; i < variationsCount; ++i) {
        if (_expression->evaluate(BooleanInterpretation::createFromNumber(i, _expression->_variables)) != expectedValue) {
            return false;
        }
    }
    return true;
}

bool ExpressionCalculator::isTautology() const {
    return checkAllVariations(true);
}

bool ExpressionCalculator::isContradiction() const {
    return checkAllVariations(false);
}
