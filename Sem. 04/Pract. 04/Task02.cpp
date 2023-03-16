#include <iostream>
#include <fstream>
#pragma warning (disable: 4996)

const size_t MAX_SIZE_NAME = 25;
const size_t MAX_SIZE_STATE = 100;
const size_t NUM_OF_TASKS = 5;

class Task {
private:
	char name[MAX_SIZE_NAME];
	char state[MAX_SIZE_STATE];
	int points;

	bool isValidName(const char* name) {
		if (name == nullptr)
			return false;

		if (strlen(name) >= MAX_SIZE_NAME)
			return false;

		return true;
	}

	bool isValidState(const char* state) {
		if (state == nullptr)
			return false;

		if (strlen(state) >= MAX_SIZE_STATE)
			return false;

		return true;
	}

public:
	Task(const char* name, const char* state, int points) {
		setName(name);
		setState(state);
		setPoints(points);
	}

	~Task() {
		delete[] name;
		delete[] state;
	}

	const char* getName() const {
		return this->name;
	}

	const char* getState() const {
		return this->state;
	}

	int getPoints() const {
		return points;
	}

	void setState(const char* state) {
		if (isValidState(state)) {
			strcpy(this->state, state);
		}
		else strcpy(this->state, "TBA");
	}

	void setName(const char* name) {
		if (isValidName(name)) {
			strcpy(this->name, name);
		}
		else strcpy(this->name, "TBA");
	}

	void setPoints(int points) {
		this->points = points;
	}

	void writeOneTaskToFile(const char* file) const {
		std::ofstream outFile(file, std::ios::out | std::ios::binary);
		if (!outFile.is_open()) {
			std::cout << "ERROR!" << std::endl;
			return;
		}
		outFile.write((const char*)name, sizeof(name));
		outFile.write((const char*)state, sizeof(state));
		outFile.write((const char*)points, sizeof(points));
		outFile.close();
	}

	void readOneTaskFromFile(const char* file) const {
		std::ifstream inFile(file, std::ios::in | std::ios::binary);
		if (!inFile.is_open()) {
			std::cout << "ERROR!" << std::endl;
			return;
		}
		inFile.read((char*)name, sizeof(name));
		inFile.read((char*)state, sizeof(state));
		inFile.read((char*)points, sizeof(points));
		inFile.close();
	}
};

struct OOPExam {
private:
	Task tasks[NUM_OF_TASKS];
	int minPoints = 10;
public:
	void writeToFile(const char* file) {
		std::ofstream outFile(file, std::ios::out | std::ios::binary);
		if (!outFile.is_open()) {
			std::cout << "ERROR!" << std::endl;
			return;
		}
		for (int i = 0; i < NUM_OF_TASKS; i++) {
			tasks[i].writeOneTaskToFile(file);
		}
		outFile.close();
	}

	void readFromFile(const char* file) {
		std::ofstream inFile(file, std::ios::in | std::ios::binary);
		if (!inFile.is_open()) {
			std::cout << "ERROR!" << std::endl;
			return;
		}
		for (int i = 0; i < NUM_OF_TASKS; i++) {
			tasks[i].writeOneTaskToFile(file);
		}
		inFile.close();
	}

	void changeMin(int newPoints) {
		this->minPoints = newPoints;
	}

	int getMax() {
		int maxPoints = 0;
		for (int i = 0; i < NUM_OF_TASKS; i++) {
			maxPoints += tasks[i].getPoints();
		}
		return maxPoints;
	}
};