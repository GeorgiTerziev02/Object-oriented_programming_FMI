#include "BinaryExpression.h"

void BinaryExpression::copyFrom(const BinaryExpression &other) {
    _operand = other._operand;
    _left = other._left->clone();
    _right = other._right->clone();
}

void BinaryExpression::moveFrom(BinaryExpression &&other) {
    _operand = other._operand;
    _left = other._left;
    _right = other._right;

    other._left = nullptr;
    other._right = nullptr;
}

void BinaryExpression::free() {
    delete _left;
    delete _right;
}

BinaryExpression::BinaryExpression(const BinaryExpression &other) : BooleanExpression(other) {
    copyFrom(other);
}

BinaryExpression::BinaryExpression(BinaryExpression &&other) noexcept : BooleanExpression(std::move(other)) {
    moveFrom(std::move(other));
}

BinaryExpression &BinaryExpression::operator=(const BinaryExpression &other) {
    if (this != &other) {
        BooleanExpression::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

BinaryExpression &BinaryExpression::operator=(BinaryExpression &&other) noexcept {
    if (this != &other) {
        BooleanExpression::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

BinaryExpression::~BinaryExpression() {
    free();
}

BinaryExpression::BinaryExpression(char operand, BooleanExpression *left, BooleanExpression *right)
    : _operand(operand), _left(left), _right(right) {
    _variablesCount = 0;
    for (size_t i = 0; i < VARIABLES_COUNT; ++i) {
        if (_left->_variables[i] || _right->_variables[i]) {
            _variables[i] = true;
            _variablesCount++;
        }
    }
}

BooleanExpression *BinaryExpression::clone() const {
    return new BinaryExpression(_operand, _left->clone(), _right->clone());
}

bool BinaryExpression::evaluate(const BooleanInterpretation &interpretation) const {
    switch (_operand) {
        case AND: return _left->evaluate(interpretation) && _right->evaluate(interpretation);
        case OR: return _left->evaluate(interpretation) || _right->evaluate(interpretation);
        case IMP: return !_left->evaluate(interpretation) && _right->evaluate(interpretation);
        case EQV: return (_left->evaluate(interpretation) && _right->evaluate(interpretation)) || (!_left->evaluate(interpretation) && !_right->evaluate(interpretation));
        default: return false;
    }
}
