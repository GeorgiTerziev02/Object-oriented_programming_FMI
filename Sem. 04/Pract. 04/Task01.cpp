#include <iostream>

const size_t MAX_SIZE_NAME = 25;

class Teacher {
private:
	char name[MAX_SIZE_NAME];
	size_t age;
	size_t experience;
public:
	Teacher() {
		age = 0;
		experience = 0;
	}

	Teacher(const char* name, size_t age, size_t experience) {
		setName(name);
		setAge(age);
		setExperience(experience);
	}

	const char* getName() const {
		return name;
	}

	size_t getAge() const {
		return age;
	}

	size_t getExperience() const {
		return experience;
	}

	void setName(const char* name) {
		strcpy(this->name, name);
	}

	void setAge(size_t age) {
		if (age >= 18 && age <= 65) { // we don`t tolerate old retired people ;)
			this->age = age;
		}
	}

	void setExperience(size_t experience) {
		if (experience >= 3) { //we need an experienced person and we don`t tolerate young people, we hate them!;)
			this->experience = experience;
		}
	}
};

int main() {
	Teacher t1;
	t1.setName("Ivan");
	t1.setAge(33);
	t1.setExperience(5);

	Teacher t2("Georgi", 20, 3);
}