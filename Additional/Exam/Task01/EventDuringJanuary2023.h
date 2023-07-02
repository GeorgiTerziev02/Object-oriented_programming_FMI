#pragma once

#include <cstdint>

class EventDuringJanuary2023 {
private:
	const static unsigned FirstDay = 7;
public:
	bool AddDay(unsigned day);
	bool RemoveDay(unsigned day);
	bool ContainsDay(unsigned day) const;
	bool CheckIfDayIsPresent(unsigned day) const;
	unsigned HowManyOnDayOfWeek(unsigned dayOfWeek);

	bool SaveToFile(const char* fileName);
	bool ReadFromFile(const char* fileName);

	friend EventDuringJanuary2023 Union(const EventDuringJanuary2023& lhs, const EventDuringJanuary2023& rhs);
	friend EventDuringJanuary2023 Interaction(const EventDuringJanuary2023& lhs, const EventDuringJanuary2023& rhs);

private:
	uint32_t m_days = 0;

};