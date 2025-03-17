#pragma once

#include <iostream>
#include <fstream>
#include "./Task.h"

using namespace std;

static const int MAX_TASKS = 10;

class Exam {
    private:
        Task tasks[MAX_TASKS];
        int taskCount;

    public:
        Exam();

        bool addTask(const Task& task);
        int getMaxPoints() const;
        bool writeToFile(const char* filename) const;
        bool readFromFile(const char* filename);

        void conductExam();
};
