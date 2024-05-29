#include "ExpressionCalculator.h"
#include <stdexcept>

namespace {
	const char AND = '^';
	const char OR = 'v';
	const char IMPL = '>'; //=>
	const char IFF = '='; // <=>
	const char XOR = '+';
	const char NEG = '!';

	bool isOperator(char ch) {
		return ch == AND || ch == OR || ch == IFF || ch == IMPL || ch == XOR || ch == NEG;
	}
}

#pragma region BooleanInterpretation

bool ExpressionCalculator::BooleanInterpretation::isValidCharacter(char ch) {
	return 'A' <= ch && ch <= 'Z';
}

ExpressionCalculator::BooleanInterpretation ExpressionCalculator::BooleanInterpretation::createFromNumber(size_t number, const bool variables[CHARACTERS_COUNT]) {
	BooleanInterpretation result;

	for (size_t i = 0; i < CHARACTERS_COUNT; i++) {
		if (variables[i]) {
			if (number & 1) { // (number % 2) != 0
				result.setValue('A' + i, true);
			}

			number >>= 1; // number /= 2
		}
	}

	return result;
}

bool ExpressionCalculator::BooleanInterpretation::getValue(char ch) const {
	if (!BooleanInterpretation::isValidCharacter(ch)) {
		throw std::exception("Invalid character");
	}

	unsigned index = ch - 'A';
	return (variables & (1 << index)) != 0;
}

void ExpressionCalculator::BooleanInterpretation::setValue(char ch, bool newValue) {
	if (!BooleanInterpretation::isValidCharacter(ch)) {
		throw std::exception("Invalid character");
	}

	unsigned index = ch - 'A';
	if (newValue) {
		variables |= (1 << index);
	}
	else {
		variables &= ~(1 << index);
	}
}

#pragma endregion

#pragma region Variable

ExpressionCalculator::Variable::Variable(char ch) : ch(ch) { }

bool ExpressionCalculator::Variable::evaluate(const BooleanInterpretation& interpretation) const {
	return interpretation.getValue(ch);
}

void ExpressionCalculator::Variable::populateUsedCharacters(bool usedCharacters[CHARACTERS_COUNT]) const {
	usedCharacters[ch - 'A'] = true;
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::Variable::clone() const {
	return new Variable(*this);
}

#pragma endregion

#pragma region Unary Expression

ExpressionCalculator::UnaryExpression::UnaryExpression(char operand, BooleanExpression* expression)
	: operand(operand), expression(expression)
{ }

bool ExpressionCalculator::UnaryExpression::evaluate(const BooleanInterpretation& interpretation) const {
	if (operand != NEG) {
		return false;
	}

	return !expression->evaluate(interpretation);
}

void ExpressionCalculator::UnaryExpression::populateUsedCharacters(bool usedCharacters[CHARACTERS_COUNT]) const {
	expression->populateUsedCharacters(usedCharacters);
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::UnaryExpression::clone() const {
	return new UnaryExpression(operand, expression->clone());
}

ExpressionCalculator::UnaryExpression::~UnaryExpression() {
	delete expression;
}

#pragma endregion

#pragma region Binary Expressions

ExpressionCalculator::BinaryExpression::BinaryExpression(BooleanExpression* left, BooleanExpression* right)
	: left(left), right(right)
{ }

void ExpressionCalculator::BinaryExpression::populateUsedCharacters(bool usedCharacters[CHARACTERS_COUNT]) const {
	left->populateUsedCharacters(usedCharacters);
	right->populateUsedCharacters(usedCharacters);
}

#pragma region Old implementation

// Old implementation where we didn't have descendants successors of the BinaryExpression class
//bool ExpressionCalculator::BinaryExpression::evaluate(const BooleanInterpretation& interpretation) const {
//	switch (operand) {
//	case OR: return  left->evaluate(interpretation) || right->evaluate(interpretation);
//	case AND: return left->evaluate(interpretation) && right->evaluate(interpretation);
//	case IMPL: return !left->evaluate(interpretation) || right->evaluate(interpretation);
//	case IFF: return left->evaluate(interpretation) == right->evaluate(interpretation);
//	case XOR: return left->evaluate(interpretation) != right->evaluate(interpretation);
//	default: return false; break;
//	}
//}


// ExpressionCalculator::BooleanExpression* ExpressionCalculator::BinaryExpression::clone() const {
//		return new BinaryExpression(operand, left->clone(), right->clone());
// }

#pragma endregion

ExpressionCalculator::BinaryExpression::~BinaryExpression() {
	delete left;
	delete right;
}

ExpressionCalculator::ORBinaryExpression::ORBinaryExpression(BooleanExpression* left, BooleanExpression* right)
	: BinaryExpression(left, right) { }

bool ExpressionCalculator::ORBinaryExpression::evaluate(const BooleanInterpretation& interpretation) const {
	return  left->evaluate(interpretation) || right->evaluate(interpretation);
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::ORBinaryExpression::clone() const {
	return new ORBinaryExpression(left->clone(), right->clone());
}

ExpressionCalculator::ANDBinaryExpression::ANDBinaryExpression(BooleanExpression* left, BooleanExpression* right)
	: BinaryExpression(left, right) { }

bool ExpressionCalculator::ANDBinaryExpression::evaluate(const BooleanInterpretation& interpretation) const {
	return left->evaluate(interpretation) && right->evaluate(interpretation);
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::ANDBinaryExpression::clone() const {
	return new ANDBinaryExpression(left->clone(), right->clone());
}

ExpressionCalculator::IMPLBinaryExpression::IMPLBinaryExpression(BooleanExpression* left, BooleanExpression* right)
	: BinaryExpression(left, right) { }

bool ExpressionCalculator::IMPLBinaryExpression::evaluate(const BooleanInterpretation& interpretation) const {
	return !left->evaluate(interpretation) || right->evaluate(interpretation);
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::IMPLBinaryExpression::clone() const {
	return new IMPLBinaryExpression(left->clone(), right->clone());
}

ExpressionCalculator::IFFBinaryExpression::IFFBinaryExpression(BooleanExpression* left, BooleanExpression* right)
	: BinaryExpression(left, right) { }

bool ExpressionCalculator::IFFBinaryExpression::evaluate(const BooleanInterpretation& interpretation) const {
	return left->evaluate(interpretation) == right->evaluate(interpretation);
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::IFFBinaryExpression::clone() const {
	return new IFFBinaryExpression(left->clone(), right->clone());
}

ExpressionCalculator::XORBinaryExpression::XORBinaryExpression(BooleanExpression* left, BooleanExpression* right)
	: BinaryExpression(left, right) { }

bool ExpressionCalculator::XORBinaryExpression::evaluate(const BooleanInterpretation& interpretation) const {
	return left->evaluate(interpretation) != right->evaluate(interpretation);
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::XORBinaryExpression::clone() const {
	return new XORBinaryExpression(left->clone(), right->clone());
}

#pragma endregion

ExpressionCalculator::BinaryExpression* ExpressionCalculator::BinaryExpressionFactory::create(char operand, BooleanExpression* left, BooleanExpression* right) {
	switch (operand) {
		case OR: return new ORBinaryExpression(left, right);
		case AND: return new ANDBinaryExpression(left, right);
		case IMPL: return new IMPLBinaryExpression(left, right);
		case IFF: return new IFFBinaryExpression(left, right);
		case XOR: return new XORBinaryExpression(left, right);
		default: return nullptr;
	}
}

#pragma region Expression Calculator

bool ExpressionCalculator::checkAllVariations(const BooleanExpression* expression, bool expectedValue) {
	bool usedCharacters[CHARACTERS_COUNT];
	expression->populateUsedCharacters(usedCharacters);
	size_t chCount = 0;
	for (size_t i = 0; i < CHARACTERS_COUNT; i++) {
		if (usedCharacters[i]) {
			chCount++;
		}
	}

	size_t variationsCount = (1 << chCount);
	for (size_t i = 0; i < variationsCount; i++) {
		if (expression->evaluate(BooleanInterpretation::createFromNumber(i, usedCharacters))
			!= expectedValue) {
			return false;
		}
	}

	return true;
}

ExpressionCalculator::BooleanExpression* ExpressionCalculator::ExpressionCalculator::parseExpression(const StringView& str) {
	if (str.length() == 0) {
		return nullptr;
	}

	if (str.length() == 1) {
		return new Variable(str[0]);
	}

	StringView strWithoutBrackets = str.substr(1, str.length() - 2);
	size_t length = strWithoutBrackets.length();
	size_t bracketsCounter = 0;
	for (size_t i = 0; i < length; i++) {
		if (strWithoutBrackets[i] == '(') {
			bracketsCounter++;
		}
		else if (strWithoutBrackets[i] == ')') {
			bracketsCounter--;
		}
		else if (isOperator(strWithoutBrackets[i]) && bracketsCounter == 0) {
			if (strWithoutBrackets[i] == NEG) {
				return new UnaryExpression(
					NEG,
					parseExpression(
						strWithoutBrackets.substr(i + 1, length - i - 1)
					)
				);
			}
			else {
				return BinaryExpressionFactory::create(
					strWithoutBrackets[i],
					parseExpression(strWithoutBrackets.substr(0, i)),
					parseExpression(strWithoutBrackets.substr(i + 1, length - i - 1))
				);
			}
		}
	}

	return nullptr;
}

ExpressionCalculator::ExpressionCalculator(const MyString& str) : expression(parseExpression(str)) { }

ExpressionCalculator::ExpressionCalculator(const ExpressionCalculator& other) {
	copyFrom(other);
}

ExpressionCalculator::ExpressionCalculator(ExpressionCalculator&& other) noexcept {
	move(std::move(other));
}

ExpressionCalculator& ExpressionCalculator::operator=(const ExpressionCalculator& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

ExpressionCalculator& ExpressionCalculator::operator=(ExpressionCalculator&& other) noexcept {
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

ExpressionCalculator::~ExpressionCalculator() {
	free();
}

bool ExpressionCalculator::isTautology() const {
	return checkAllVariations(expression, true);
}

bool ExpressionCalculator::isContradiction() const {
	return checkAllVariations(expression, false);
}

void ExpressionCalculator::copyFrom(const ExpressionCalculator& other) {
	expression = other.expression->clone();
}

void ExpressionCalculator::move(ExpressionCalculator&& other) {
	expression = other.expression;
	other.expression = nullptr;
}

void ExpressionCalculator::free() {
	delete expression;
}

#pragma endregion
