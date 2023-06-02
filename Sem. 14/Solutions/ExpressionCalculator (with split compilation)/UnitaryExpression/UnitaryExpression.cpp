#include "UnitaryExpression.h"

void UnitaryExpression::copyFrom(const UnitaryExpression &other) {
    _operand = other._operand;
    _expression = other._expression->clone();
}

void UnitaryExpression::moveFrom(UnitaryExpression &&other) {
    _operand = other._operand;
    _expression = other._expression;

    other._expression = nullptr;
}

void UnitaryExpression::free() {
    delete _expression;
}

UnitaryExpression::UnitaryExpression(const UnitaryExpression &other) : BooleanExpression(other) {
    copyFrom(other);
}

UnitaryExpression::UnitaryExpression(UnitaryExpression &&other) noexcept : BooleanExpression(std::move(other)) {
    moveFrom(std::move(other));
}

UnitaryExpression &UnitaryExpression::operator=(const UnitaryExpression &other) {
    if (this != &other) {
        BooleanExpression::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

UnitaryExpression &UnitaryExpression::operator=(UnitaryExpression &&other) noexcept {
    if (this != &other) {
        BooleanExpression::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

UnitaryExpression::~UnitaryExpression() {
    free();
}

UnitaryExpression::UnitaryExpression(char operand, BooleanExpression *expression) : _operand(operand), _expression(expression) {
    _variablesCount = expression->_variablesCount;
    for (size_t i = 0; i < VARIABLES_COUNT; ++i) {
        _variables[i] = expression->_variables[i];
    }
}

BooleanExpression *UnitaryExpression::clone() const {
    return new UnitaryExpression(_operand, _expression->clone());
}

bool UnitaryExpression::evaluate(const BooleanInterpretation &interpretation) const {
    return !_expression->evaluate(interpretation);
}
