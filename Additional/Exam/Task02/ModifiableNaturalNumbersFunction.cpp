#include "ModifiableNaturalNumbersFunction.hpp"

#include <iostream>

ModifiableNaturalNumbersFunction::ModifiableNaturalNumbersFunction()
	: ModifiableNaturalNumbersFunction(), m_capacity(2) { 
	m_pModifiedPoints = new Pair[m_capacity];
}

ModifiableNaturalNumbersFunction::ModifiableNaturalNumbersFunction(UnaryUnsignedFunction pFunc, unsigned pointsToChange)
	: NaturalNumbersFunction(pFunc) {
	m_capacity = pointsToChange;
	m_pModifiedPoints = new Pair[m_capacity];
}

ModifiableNaturalNumbersFunction::ModifiableNaturalNumbersFunction(const ModifiableNaturalNumbersFunction& other) 
	: NaturalNumbersFunction(other) {
	CopyFrom(other);
}

ModifiableNaturalNumbersFunction::ModifiableNaturalNumbersFunction(ModifiableNaturalNumbersFunction&& other) noexcept
	: NaturalNumbersFunction(std::move(other)) {
	MoveFrom(std::move(other));
}

ModifiableNaturalNumbersFunction& ModifiableNaturalNumbersFunction::operator=(const ModifiableNaturalNumbersFunction& other) {
	if (this != &other) {
		Free();
		NaturalNumbersFunction::operator=(other);
		CopyFrom(other);
	}

	return *this;
}

ModifiableNaturalNumbersFunction& ModifiableNaturalNumbersFunction::operator=(ModifiableNaturalNumbersFunction&& other) noexcept {
	if (this != &other) {
		Free();
		NaturalNumbersFunction::operator=(std::move(other));
		MoveFrom(std::move(other));
	}

	return *this;
}

ModifiableNaturalNumbersFunction::~ModifiableNaturalNumbersFunction() {
	Free();
}

bool ModifiableNaturalNumbersFunction::Modify(unsigned point, unsigned value) {
	int index = FindPointIndex(point);
	if (InvalidIndex == index) {
		if (m_currentSize >= m_capacity) {
			return false;
		}
		index = m_currentSize++;
	}
	m_pModifiedPoints[index].m_point = point;
	m_pModifiedPoints[index].m_value = value;

	return true;
}

bool ModifiableNaturalNumbersFunction::RemoveModification(unsigned point) {
	int index = FindPointIndex(point);
	if (InvalidIndex == index) {
		return false;
	}

	m_pModifiedPoints[index] = Pair();
	if (index != --m_currentSize) {
		std::swap(m_pModifiedPoints[index], m_pModifiedPoints[m_currentSize]);
	}

	return true;
}

unsigned ModifiableNaturalNumbersFunction::Eval(unsigned value) const {
	int index = FindPointIndex(value);

	return InvalidIndex == index ? m_pFunc(value) : m_pModifiedPoints[index].m_value;
}

void ModifiableNaturalNumbersFunction::SetFunction(UnaryUnsignedFunction pFunc) {
	RemoveAllModifications();

	m_pFunc = pFunc;
}

void ModifiableNaturalNumbersFunction::CopyFrom(const ModifiableNaturalNumbersFunction& other) {
	m_capacity = other.m_capacity;
	m_pModifiedPoints = new Pair[m_capacity];
	
	for (unsigned i = 0; i < m_currentSize; ++i) {
		m_pModifiedPoints[i] = other.m_pModifiedPoints[i];
	}
}

void ModifiableNaturalNumbersFunction::MoveFrom(ModifiableNaturalNumbersFunction&& other) {
	m_capacity = other.m_capacity;
	m_pModifiedPoints = other.m_pModifiedPoints;
	
	other.m_capacity = 0;
	other.m_pModifiedPoints = nullptr;
}

void ModifiableNaturalNumbersFunction::Free() {
	delete[] m_pModifiedPoints;
}

int ModifiableNaturalNumbersFunction::FindPointIndex(unsigned point) const {
	for (unsigned i = 0; i < m_currentSize; ++i) {
		if (point == m_pModifiedPoints[i].m_point) {
			return i;
		}
	}

	return InvalidIndex;
}

void ModifiableNaturalNumbersFunction::RemoveAllModifications() {
	m_currentSize = 0;
}
