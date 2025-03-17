#pragma once

#include <iostream>

static const int CONDITION_LENGTH = 256;
static const int PASSWORD_LENGTH = 50;

class Task {
private:
    char condition[CONDITION_LENGTH];
    char correctAnswer;
    int points;
    char password[PASSWORD_LENGTH];

public:
    Task();
    Task(const char* cond, char correct, int pts, const char* pass);

    const char* getCondition() const;
    char getCorrectAnswer() const;
    int getPoints() const;

    bool setCondition(const char* newCond, const char* pass);
    bool setCorrectAnswer(char newAnswer, const char* pass);
    bool setPoints(int newPoints, const char* pass);
};
