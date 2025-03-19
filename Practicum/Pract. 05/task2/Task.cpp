#include "./Task.h"

Task::Task() : correctAnswer('a'), points(0) {
    memset(condition, 0, CONDITION_LENGTH);
    strncpy_s(condition, "New task", CONDITION_LENGTH - 1);
    memset(password, 0, PASSWORD_LENGTH);
    strncpy_s(password, "Default", PASSWORD_LENGTH - 1);
}

Task::Task(const char* cond, char correct, int pts, const char* pass) : correctAnswer(correct), points(pts) {
    memset(condition, 0, CONDITION_LENGTH);
    strncpy_s(condition, cond, CONDITION_LENGTH - 1);
    memset(password, 0, PASSWORD_LENGTH);
    strncpy_s(password, pass, PASSWORD_LENGTH - 1);
}

const char* Task::getCondition() const {
    return condition;
}

char Task::getCorrectAnswer() const {
    return correctAnswer;
}

int Task::getPoints() const {
    return points;
}

bool Task::setCondition(const char* newCond, const char* pass) {
    if (strcmp(pass, password) == 0 && newCond) {
        memset(condition, 0, CONDITION_LENGTH);
        strncpy_s(condition, newCond, CONDITION_LENGTH - 1);
        return true;
    }
    return false;
}

bool Task::setCorrectAnswer(char newAnswer, const char* pass) {
    if (strcmp(pass, password) == 0) {
        if (newAnswer == 'a' || newAnswer == 'b' || newAnswer == 'c' || newAnswer == 'd') {
            correctAnswer = newAnswer;
            return true;
        }
    }
    return false;
}

bool Task::setPoints(int newPoints, const char* pass) {
    if (strcmp(pass, password) == 0 && newPoints >= 0) {
        points = newPoints;
        return true;
    }
    return false;
}