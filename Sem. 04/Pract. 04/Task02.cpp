#include <iostream>
#include <fstream>

#pragma warning( disable : 4996)

const unsigned ARRAY_SIZE = 3;

class Task {
private:
	char* name = nullptr;
	char* description = nullptr;
	unsigned points = 0;

public:
	Task() {
		name = nullptr;
		description = nullptr;
		points = 0;
	}
	void setName(const char* name) {
		if (this->name != nullptr) {
			delete[] this->name;
		}
		
		unsigned nameLen = 0;
		nameLen = strlen(name);

		this->name = new char[nameLen + 1];
		strcpy(this->name, name);
	}
	void setNameFromFile(std::ifstream& ifs, unsigned nameLen) {
		this->name = new char[nameLen+1];
		ifs.read(this->name, nameLen);
		this->name[nameLen] = '\0';
	}

	void setDescription(const char* description) {
		if (this->description != nullptr) {
			delete[] this->description;
		}

		unsigned nameLen = 0;
		nameLen = strlen(description);

		this->description = new char[nameLen + 1];
		strcpy(this->description, description);
		this->description[nameLen] = '\0';
	}

	void setDescriptionFromFile(std::ifstream& ifs, unsigned descriptionLen) {
		this->description = new char[descriptionLen + 1];
		ifs.read(this->name, descriptionLen);
		this->description[descriptionLen] = '\0';
	}

	void setPoints(unsigned points) {
		this->points = points;
	}

	const char* getName() const {
		return name;
	}

	const char* getDescription() const {
		return description;
	}

	unsigned getPoints() const {
		return points;
	}

	void print() {
		const char* name = getName();
		unsigned nameLen = strlen(name);
		for (int i = 0; i < nameLen; i++) {
			std::cout << name[i];
		}

		const char* description = getDescription();
		unsigned desLen = strlen(description);
		for (int i = 0; i < desLen; i++) {
			std::cout << description[i];
		}
		std::cout << getPoints() << std::endl;
	}

	~Task() {
		delete[] name;
		delete[] description;
	}
};

class Exam {
private:
	Task tasks[ARRAY_SIZE];
	unsigned minPoints;

public:
	Exam() {

	}
	Exam(const Task* tasks, unsigned minPoints) {
		for (int i = 0; i < ARRAY_SIZE; i++) {
			this->tasks[i].setName(tasks[i].getName());
			this->tasks[i].setDescription(tasks[i].getDescription());
			this->tasks[i].setPoints(tasks[i].getPoints());
		}
		this->minPoints = minPoints;
	}
	void setPoints(unsigned minPoints) {
		this->minPoints = minPoints;
	}
	void changeMin(unsigned minPoints) {
		this->minPoints = minPoints;
	}

	void writeToFile(const char* filename) const{

		std::ofstream ofs(filename, std::ios::out | std::ios::binary | std::ios::trunc);
		
		if (!ofs.is_open()) {
			std::cout << "Error";
			return;
		}

		for (int i = 0; i < ARRAY_SIZE; i++) {
			unsigned nameLen = strlen(tasks[i].getName());
			ofs.write((const char*)&nameLen, sizeof(nameLen));

			ofs.write((const char*)tasks[i].getName(), nameLen);

			unsigned descriptionLen = strlen(tasks[i].getDescription());
			ofs.write((const char*)&descriptionLen, sizeof(descriptionLen));

			ofs.write((const char*)tasks[i].getDescription(), descriptionLen);
			
			int x = (tasks[i].getPoints());
			ofs.write((const char*)&x, sizeof(unsigned));
		}
		ofs.write((const char*)&minPoints, sizeof(unsigned));

		ofs.close();
	}


	void readFromFile(const char* filename){
		std::ifstream ifs(filename, std::ios::in | std::ios::binary);

		if (!ifs.is_open()) {
			std::cout << "Error";
			return;
		}

		for (int i = 0; i < ARRAY_SIZE; i++) {
			unsigned nameLen;
			ifs.read((char*)&nameLen, sizeof(nameLen));

			this->tasks[i].setNameFromFile(ifs, nameLen);

			unsigned descriptionLen;
			ifs.read((char*)&descriptionLen, sizeof(descriptionLen));

			this->tasks[i].setDescriptionFromFile(ifs, descriptionLen);

			unsigned points;
			ifs.read((char*)&points, sizeof(unsigned));
			this->tasks[i].setPoints(points);
		}
		unsigned minP;
		ifs.read((char*)&minP, sizeof(unsigned));
		this->minPoints=minP;
	
		ifs.close();
	}
	void print() {
		for (int i = 0; i < ARRAY_SIZE; i++) {
			tasks[i].print();
		}
		std::cout << minPoints << std::endl;
	}
};

int main() {
	Task arr[3];
	arr[0].setName("test 1");
	arr[0].setDescription("easy");
	arr[0].setPoints(10);

	arr[1].setName("test 2");
	arr[1].setDescription("medium");
	arr[1].setPoints(20);

	arr[2].setName("test 3");
	arr[2].setDescription("difficult");
	arr[2].setPoints(50);

	Exam ex(arr, 5);

	ex.writeToFile("Task02.dat");
	ex.readFromFile("Task02.dat");
	ex.print();
}