#include "EventDuringJanuary2023.h"

#include <iostream>
#include <fstream>

static const short MaxDays = 31; // Represents max days of January
static const short LastDayOfWeek = 7; // Represents last day of the week - Sunday

bool EventDuringJanuary2023::AddDay(unsigned day) {
	if (0 == day || day > MaxDays) {
		return false;
	}

	m_days |= (1 << day);
	return true;
}

bool EventDuringJanuary2023::RemoveDay(unsigned day) {
	if (0 == day || day > MaxDays) {
		return false;
	}

	m_days ^= (1 << day);
	return true;
}

bool EventDuringJanuary2023::ContainsDay(unsigned day) const {
	if (0 == day || day > MaxDays) {
		return false;
	}
	uint32_t mask = 1 << day;

	return (m_days & mask);
}

unsigned EventDuringJanuary2023::HowManyOnDayOfWeek(unsigned dayOfWeek) {
	if (0 == dayOfWeek || dayOfWeek > LastDayOfWeek) {
		throw std::invalid_argument("Day of week is invalid!");
	}

	unsigned counter = 0;
	unsigned offset = (LastDayOfWeek == dayOfWeek) ? 0 : dayOfWeek;
	for (unsigned i = 1 + offset; i <= MaxDays; i += LastDayOfWeek) {
		if (ContainsDay(i)) {
			++counter;
		}
	}

	return counter;
}

bool EventDuringJanuary2023::SaveToFile(const char* fileName) {
	std::ofstream file(fileName, std::ios::binary);

	if (!file) {
		std::cerr << "Error opening the file." << std::endl;
		return false;
	}

	file.write(reinterpret_cast<const char*>(&m_days), sizeof(uint32_t));
	file.close();

	return true;
}

bool EventDuringJanuary2023::ReadFromFile(const char* fileName) {
	std::ifstream file(fileName, std::ios::binary);

	if (!file) {
		std::cerr << "Error opening the file." << std::endl;
		return false;
	}

	file.read(reinterpret_cast<char*>(&m_days), sizeof(uint32_t));
	file.close();

	return true;
}

EventDuringJanuary2023 Union(const EventDuringJanuary2023& lhs, const EventDuringJanuary2023& rhs) {
	EventDuringJanuary2023 result;
	result.m_days = lhs.m_days | rhs.m_days;

	return result;
}

EventDuringJanuary2023 Interaction(const EventDuringJanuary2023& lhs, const EventDuringJanuary2023& rhs) {
	EventDuringJanuary2023 result;
	result.m_days = lhs.m_days & rhs.m_days;

	return result;
}