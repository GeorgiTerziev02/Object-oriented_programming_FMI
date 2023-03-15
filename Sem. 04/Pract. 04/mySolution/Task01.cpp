#include <iostream>
#include <cstring>

const size_t MAX_NAME_LENGTH = 25;
const int MAX_AGE = 123;
const int MAX_INTERNSHIP_YEARS = 70;

size_t getLength(const char* str)
{
	size_t length = 0;
	while (*str != '\0')
	{
		str++;
		length++;
	}

	return length;
}

void strCopy(char* direction, const char* toCopy)
{
	size_t toCopyLength = getLength(toCopy);

	for (size_t i = 0; i < toCopyLength; i++)
	{
		direction[i] = toCopy[i];
	}

	direction[toCopyLength] = '\0';
}

class Teacher
{
public:
	Teacher() {
		name = new char[MAX_NAME_LENGTH];
		age = 0;
		internshipYears = 0;
	}

	Teacher(const char* nameToSet, unsigned int ageToSet, unsigned int internshipYearsToSet) {
		name = new char[MAX_NAME_LENGTH];
		setName(nameToSet);
		setAge(ageToSet);
		setInternshipYears(internshipYearsToSet);
	}

	const char* getName() const {
		return name;
	}

	unsigned int getAge() const {
		return age;
	}
	unsigned int getInternshipYears() const {
		return internshipYears;
	}
	void setName(const char* nameToSet) {
		if (getLength(nameToSet) >= MAX_NAME_LENGTH)
		{
			strCopy(name, "");
			return;
		}
		strCopy(name, nameToSet);
	}

	void setAge(unsigned int ageToSet) {
		if (ageToSet > MAX_AGE)
		{
			age = 0;
			return;
		}
		age = ageToSet;
	}

	void setInternshipYears(unsigned int internshipYearsToSet) {
		if (internshipYearsToSet > MAX_INTERNSHIP_YEARS)
		{
			internshipYearsToSet = 0;
			return;
		}
		internshipYears = internshipYearsToSet;
	}

	void print() const {
		std::cout << name << " " << age << " " << internshipYears;
	}

	~Teacher()
	{
		delete[] name;
	}

private:
	char* name;
	unsigned int age;
	unsigned int internshipYears;
};


int main()
{
	Teacher t("Ivan", 45, 12);

	t.print();

	t.setName("Noris");
	t.setAge(59);
	t.setInternshipYears(26);

	t.print();
}