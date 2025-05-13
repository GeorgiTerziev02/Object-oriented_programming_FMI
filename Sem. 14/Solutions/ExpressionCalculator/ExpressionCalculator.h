#pragma once
#include "StringView.h"

class ExpressionCalculator {
private:
	static const short CHARACTERS_COUNT = 26;

	class BooleanInterpretation {
	private:
		// This contains the value of the characters as a bitset
		uint32_t variables = 0;
	public:
		bool getValue(char ch) const;
		void setValue(char ch, bool value);

		static bool isValidCharacter(char ch);
		static BooleanInterpretation createFromNumber(size_t number, const bool variables[CHARACTERS_COUNT]);
	};

#pragma region Expressions

	class BooleanExpression {
	public:
		virtual bool evaluate(const BooleanInterpretation& interpretation) const = 0;
		virtual void populateUsedCharacters(bool usedCharacters[CHARACTERS_COUNT]) const = 0;
		virtual BooleanExpression* clone() const = 0;
		virtual ~BooleanExpression() = default;
	};

	class Variable : public BooleanExpression {
	private:
		char ch;
	public:
		Variable(char ch);
		bool evaluate(const BooleanInterpretation& interpretation) const override;
		void populateUsedCharacters(bool usedCharacters[CHARACTERS_COUNT]) const override;
		BooleanExpression* clone() const override;
	};

	class UnaryExpression : public BooleanExpression {
	private:
		char operand;
		BooleanExpression* expression;
	public:
		UnaryExpression(char operand, BooleanExpression* expression);
		bool evaluate(const BooleanInterpretation& interpretation) const override;
		void populateUsedCharacters(bool usedCharacters[CHARACTERS_COUNT]) const override;
		BooleanExpression* clone() const override;
		~UnaryExpression();
	};

#pragma region BinaryExpressions

	// Abstract class
	class BinaryExpression : public BooleanExpression {
	protected:
		BooleanExpression* left;
		BooleanExpression* right;
	public:
		BinaryExpression(BooleanExpression* left, BooleanExpression* right);
		void populateUsedCharacters(bool usedCharacters[CHARACTERS_COUNT]) const override;
		// evaluate is not overwritten!
		~BinaryExpression();
	};

	class ORBinaryExpression : public BinaryExpression {
	public:
		ORBinaryExpression(BooleanExpression* left, BooleanExpression* right);
		bool evaluate(const BooleanInterpretation& interpretation) const override;
		BooleanExpression* clone() const override;
	};

	class ANDBinaryExpression : public BinaryExpression {
	public:
		ANDBinaryExpression(BooleanExpression* left, BooleanExpression* right);
		bool evaluate(const BooleanInterpretation& interpretation) const override;
		BooleanExpression* clone() const override;
	};

	class IMPLBinaryExpression : public BinaryExpression {
	public:
		IMPLBinaryExpression(BooleanExpression* left, BooleanExpression* right);
		bool evaluate(const BooleanInterpretation& interpretation) const override;
		BooleanExpression* clone() const override;
	};

	class IFFBinaryExpression : public BinaryExpression {
	public:
		IFFBinaryExpression(BooleanExpression* left, BooleanExpression* right);
		bool evaluate(const BooleanInterpretation& interpretation) const override;
		BooleanExpression* clone() const override;
	};

	class XORBinaryExpression : public BinaryExpression {
	public:
		XORBinaryExpression(BooleanExpression* left, BooleanExpression* right);
		bool evaluate(const BooleanInterpretation& interpretation) const override;
		BooleanExpression* clone() const override;
	};

	class BinaryExpressionFactory {
	public:
		static BinaryExpression* create(char operand, BooleanExpression* left, BooleanExpression* right);
	};

#pragma endregion
#pragma endregion
	
	BooleanExpression* expression = nullptr;

	static bool checkAllVariations(const BooleanExpression* expression, bool expectedValue);
	static BooleanExpression* parseExpression(const StringView& str);
public:
	ExpressionCalculator(const MyString& str);
	ExpressionCalculator(const ExpressionCalculator& other);
	ExpressionCalculator(ExpressionCalculator&& other) noexcept;
	ExpressionCalculator& operator=(const ExpressionCalculator& other);
	ExpressionCalculator& operator=(ExpressionCalculator&& other) noexcept;
	~ExpressionCalculator();

	bool isTautology() const;
	bool isContradiction() const;

private:
	void copyFrom(const ExpressionCalculator& other);
	void move(ExpressionCalculator&& other);
	void free();
};
