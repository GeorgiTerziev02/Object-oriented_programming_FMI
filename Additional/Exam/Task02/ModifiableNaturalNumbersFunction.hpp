#pragma once

#include "NaturalNumbersFunction.hpp"

class ModifiableNaturalNumbersFunction : protected NaturalNumbersFunction {
private:
	static const int InvalidPoint = -1;
	static const int InvalidIndex = -1;

public:
	ModifiableNaturalNumbersFunction();
	ModifiableNaturalNumbersFunction(UnaryUnsignedFunction pFunc, unsigned pointsToChange);
	ModifiableNaturalNumbersFunction(const ModifiableNaturalNumbersFunction& other);
	ModifiableNaturalNumbersFunction(ModifiableNaturalNumbersFunction&& other) noexcept;
	ModifiableNaturalNumbersFunction& operator=(const ModifiableNaturalNumbersFunction& other);
	ModifiableNaturalNumbersFunction& operator=(ModifiableNaturalNumbersFunction&& other) noexcept;
	~ModifiableNaturalNumbersFunction();

public:
	bool Modify(unsigned point, unsigned value);
	bool RemoveModification(unsigned point);

	using NaturalNumbersFunction::CountFixedPoints;

	unsigned Eval(unsigned value) const final;
	void SetFunction(UnaryUnsignedFunction pFunc) final;

private:
	void CopyFrom(const ModifiableNaturalNumbersFunction& other);
	void MoveFrom(ModifiableNaturalNumbersFunction&& other);
	void Free();

	int FindPointIndex(unsigned point) const;
	void RemoveAllModifications();

private:
	struct Pair {
		int m_point = -1;
		int m_value = -1;
	};

	Pair* m_pModifiedPoints = nullptr;
	unsigned m_capacity = 0;
	unsigned m_currentSize = 0;
};
