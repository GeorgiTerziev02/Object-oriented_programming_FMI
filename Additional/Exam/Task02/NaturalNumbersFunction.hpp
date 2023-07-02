#pragma once

using UnaryUnsignedFunction = unsigned(*)(unsigned);

class NaturalNumbersFunction {
public:
	NaturalNumbersFunction();
	explicit NaturalNumbersFunction(UnaryUnsignedFunction pFunc);
	virtual ~NaturalNumbersFunction() = default;

public:
	unsigned CountFixedPoints(int lowerBound, int upperBound) const;

	virtual unsigned Eval(unsigned value) const;
	virtual void SetFunction(UnaryUnsignedFunction pFunc);

protected:
	UnaryUnsignedFunction m_pFunc;

};

bool CheckBounds(int& lowerBound, int& upperBound);
bool CheckFunctionsInInterval(const NaturalNumbersFunction& lhs, const NaturalNumbersFunction& rhs,
	int lowerBound, int upperBound);