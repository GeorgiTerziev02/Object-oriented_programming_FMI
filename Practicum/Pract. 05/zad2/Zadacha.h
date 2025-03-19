#pragma once
const unsigned TEXT_SIZE = 100;
const unsigned PASS_SIZE = 10;

class Zadacha
{
private:
	char text[TEXT_SIZE];
	char correctAnswer;
	double points;
	char password[PASS_SIZE];

	void setText(const char* text);
	void setPass(const char* pass);
	void setPoints(double points);

public:
	Zadacha();
	Zadacha(const char* text, char correctAnswer,double points,const char* password);

	const char* getText() const;
	

	const char getCorrect() const;
	void setCorrect(char correctAnswer);

	double getPoints() const;
	

	const char* getPass() const;
	

	bool changesZadacha(const char* password);

};

