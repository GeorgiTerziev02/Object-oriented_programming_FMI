#include "Zadacha.h"
#include <cstring>
#include <iostream>




Zadacha::Zadacha()
{

}

Zadacha::Zadacha(const char* text, char correctAnswer,
double points, const char* password)
{
	setText(text);
	setCorrect(correctAnswer);
	setPoints(points);
	setPass(password);
}

const char* Zadacha::getText() const
{
	return this->text;
}
void Zadacha::setText(const char* text)
{
	if (text && strlen(text))
		if (strlen(text) < TEXT_SIZE)
			strcpy(this->text, text);
}

const char Zadacha::getCorrect() const
{
	return this->correctAnswer;
}
void Zadacha::setCorrect(char correctAnswer)
{
	if (correctAnswer >= 'a' && correctAnswer <= 'd')
		this->correctAnswer = correctAnswer;
}

double Zadacha::getPoints() const 
{
	return this->points;
}
void Zadacha::setPoints(double points)
{
	if (points > 0)
		this->points = points;
}

const char* Zadacha::getPass() const
{
	return this->password;
}
void Zadacha::setPass(const char* pass)
{
	if (pass && strlen(pass))
		if (strlen(pass) < PASS_SIZE)
			strcpy(this->password, pass);

}
bool Zadacha::changesZadacha(const char* password)
{
	bool access = false;
	if (strcmp(this->password, password) == 0)
		access = true;

	if (access)
	{
		std::cout << "Enter  1 for change in text, 2 for change in point,"
			<< " 3 for change of password, 0 for exit ";
		int command;
		std::cin >> command;
		while (command)
		{
			if (command == 1)
			{
				char text[TEXT_SIZE];
				std::cout << "Enter a new text for the object\n";
				std::cin >> text;
				setText(text);
			}

			else if (command == 2)
			{
				unsigned points;
				std::cout << "Enter  points for the object\n";
				std::cin >> text;
				setPoints(points);
			}
			else if (command == 3)
			{
				char pass[PASS_SIZE];
				std::cin >> pass;
				setPass(pass);
			}
			else if (command == 0)
				break;
		}

	}
	else 
	{
		std::cout << "You dont have access to the object\n";
		return access;
	}
	return access;
}
