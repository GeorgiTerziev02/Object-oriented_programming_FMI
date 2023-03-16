#include<iostream>
#include<fstream>
#pragma warning(disable:4996)

const int MAX_SIZE = 64;
const int MAX_GAMES = 25;
const int MAX =  9999999;
const int MIN = -9999999;
const char fileName[10] = "games.txt";

char* strCopy(char* destination, const char* source)
{
	if (destination == NULL) {
		return NULL;
	}

	char* ptr = destination;
	
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';

	return ptr;
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

class Game {
private:
	char title[MAX_SIZE];
	int price;
	bool isAvailable;
public:
	Game() {
		strCopy(this->title, "Basic Game");
		this->price = 0;
		this->isAvailable = false;
	}
	
	Game(const char* title, const int price, const bool isAvailable) {
		strCopy(this->title, title);
		this->price = price;
		this->isAvailable = isAvailable;
	}

	const char* getTitle() const {
		return this->title;
	}
	
	const int getPrice() const {
		return this->price;
	}

	const bool getAvailabilty() const {
		return this->isAvailable;
	}

	void setTitle(const char* title) {
		strCopy(this->title, title);
	}

	void setPrice(const int price) {
		this->price = price;
	}

	void setAvailability(const bool isAvailable) {
		this->isAvailable=isAvailable;
	}

	bool isFree() const {
		if (this->price == 0) {
			return true;
		}
		return false;
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
		out << this->getTitle() << this->getPrice() << this->getAvailabilty();
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
	Game* Games;
	int size = 0;
public:
	GamePlatform() {
		this->Games = nullptr;
		this->size = 0;
	};

	GamePlatform(const char* title,const int price,const  bool isAvailable) {
		if (this->size > MAX_GAMES) {
			std::cout << "You hava reached the max number of games" << std::endl;
			return;
		}
		this->Games[this->size].setTitle(title);
		this->Games[this->size].setPrice(price);
		this->Games[this->size].setAvailability(isAvailable);
		this->size++;
	}

	void printGame(const int index) const {
		this->Games[index].print();
	}

	void printAllGame() const {
		for (int i = 0; i < this->size; i++) {
			this->Games[i].print();
		}
	}
		
	void cheapestGame() const {
		int min = MAX;
		for (int i = 0; i < this->size; i++) {
			if (this->Games[i].getPrice() < min) {
				min = this->Games[size].getPrice();
			}
		}
		for(int i=0;i<this->size;i++){
			if (this->Games[i].getPrice() == min) {
				this->Games[i].print();
			}
		}
	}

	void mostExpensiveGame() const {
		int max = MIN;
		for (int i = 0; i < this->size; i++) {
			if (this->Games[i].getPrice() > max) {
				max = this->Games[size].getPrice();
			}
		}
		for (int i = 0; i < this->size; i++) {
			if (this->Games[i].getPrice() == max) {
				this->Games[i].print();
			}
		}
	}

	void printAllFreeGame() const {
		for (int i = 0; i < this->size; i++) {
			if (this->Games[i].getPrice() == 0) {
				this->Games[i].print();
			}
		}
	}

	void removeGame(const char* titleToRemove) {
		GamePlatform Games2;
		for (int i = 0; i < this->size; i++) {
			if (strcmp(this->Games[i].getTitle(), titleToRemove) != 0) {
				Games2.Games[i] = this->Games[i];
			}
		}
		this->Games = Games2.Games;
		this->size--;
	}

	void writeToFile() const {
		std::ofstream out(fileName, std::ios::app);
		if (!out.is_open()) {
			return;
		}
		for (int i = 0; i < this->size; i++) {
			this->Games[i].writeGameToFile(out);
		}
	}

	void readToFile()  {
		std::ifstream in(fileName, std::ios::in);
		if (!in.is_open()) {
			return;
		}
		int i = 0;
		while (!in.eof()) {
			this->Games[i++].readGameFromFile(in);
		}
	}



	~GamePlatform() {
		delete[] Games;
	}
};

int main() {

}