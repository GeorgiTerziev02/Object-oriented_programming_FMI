#include<iostream>
#include<fstream>
#pragma warning(disable:4996)

const int MAX_SIZE = 64;
const int MAX_GAMES = 25;
const int MAX =  9999999;
const int MIN = -9999999;
const char fileName[10] = "games.txt";

void strCopy(char* destination, const char* source)
{
	if (destination == NULL) {
		return ;
	}
	
	if (source == NULL) {
		return;
	}

	char* ptr = destination;

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';

	destination = ptr;
}

int strCompare(const char* X, const char* Y)
{
	while (*X)
	{
		if (*X != *Y) {
			break;
		}
		X++;
		Y++;
	}
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}

size_t strLen(const char* s) {
	size_t count = 0;
	while (*s != '\0') {
		count++;
		s++;
	}
	return count;
}

class Game {
private:
	char title[MAX_SIZE];
	double price;
	bool isAvailable;
public:
	Game() {
		strCopy(this->title, "Basic Game");
		this->price = 0;
		this->isAvailable = false;
	}
	
	Game(char* title, double price, bool isAvailable) {
		if (strLen(title) < MAX_SIZE) {
			
		}
		this->price = price;
		this->isAvailable = isAvailable;
	}

	const char* getTitle() const {
		return this->title;
	}
	
	double getPrice() const {
		return this->price;
	}

	bool getAvailabilty() const {
		return this->isAvailable;
	}

	void setTitle(const char* title) {
		strCopy(this->title, title);
	}

	void setPrice(double price) {
		this->price = price;
	}

	void setAvailability(bool isAvailable) {
		this->isAvailable=isAvailable;
	}

	bool isFree() const {
		this->price == 0 ?  false : true;
	}

	void print() const {
		std::cout << "Game title: " << this->title<<std::endl;
		std::cout << "Game price: " << this->price << std::endl;
		std::cout << std::boolalpha << "Is the game available" << this->isAvailable << std::endl;
	}


	void writeGameToFile(std::ofstream& out) const {
		if (!out.is_open()) {
			return;
		}
		out << this->title << this->price << this->isAvailable;
	}

	void readGameFromFile(std::ifstream& in) {
		if (!in.is_open()) {
			return;
		}

		in >> this->title >> this->price >> this->isAvailable;
	}

	~Game() {};
};

class GamePlatform {
private:
	Game* games;
	int size;
public:
	GamePlatform() {
		size = 0;
	}

	void addGame(const char* title,double price,bool isAvailable) {
		if (this->size > MAX_GAMES) {
			std::cout << "You hava reached the max number of games" << std::endl;
			return;
		}
		this->games[this->size].setTitle(title);
		this->games[this->size].setPrice(price);
		this->games[this->size].setAvailability(isAvailable);
		this->size++;
	}

	void printGame(size_t index) const {
		if (index < this->size) {
			this->games[index].print();
		}
	}

	void printAllGame() const {
		for (int i = 0; i < this->size; i++) {
			this->games[i].print();
		}
	}
		
	void cheapestGame() const {
		int min = INT_MAX;
		for (int i = 0; i < this->size; i++) {
			if (this->games[i].getPrice() < min) {
				min = this->games[size].getPrice();
			}
		}
		for(int i=0;i<this->size;i++){
			if (this->games[i].getPrice() == min) {
				this->games[i].print();
			}
		}
	}

	void mostExpensiveGame() const {
		int max = INT_MIN;
		for (int i = 0; i < this->size; i++) {
			if (this->games[i].getPrice() > max) {
				max = this->games[size].getPrice();
			}
		}
		for (int i = 0; i < this->size; i++) {
			if (this->games[i].getPrice() == max) {
				this->games[i].print();
			}
		}
	}

	void printAllFreeGame() const {
		for (int i = 0; i < this->size; i++) {
			if (this->games[i].isFree()) {
				this->games[i].print();
			}
		}
	}

	void removeGame(const char* titleToRemove) {
		int indexToRemove=-1;
		for (int i = 0; i < this->size; i++) {
			if (strCompare(this->games[i].getTitle(), titleToRemove) == 0) {
				indexToRemove = i;
			}
		}
		this->games[indexToRemove] = this->games[this->size];
		this->size--;
	}

	void writeToFile() const {
		std::ofstream out(fileName, std::ios::app);
		if (!out.is_open()) {
			return;
		}
		
		out.write((const char*)this->size, sizeof(this->size));
		
		for (int i = 0; i < this->size; i++) {
			this->games[i].writeGameToFile(out);
		}
	}

	void readToFile()  {
		std::ifstream in(fileName, std::ios::in);
		if (!in.is_open()) {
			return;
		}
		in.read((char*)this->size, sizeof(this->size));
		for (int i = 0; i < this->size; i++) {
			this->games[i].readGameFromFile(in);
		}
	}



	~GamePlatform() {
		delete[] games;
	}
};

int main() {

}