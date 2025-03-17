#include "./Exam.h"

ostream& operator<<(ostream& os, const Task& task) {
    os.write(reinterpret_cast<const char*>(&task), sizeof(Task));
    return os;
}

istream& operator>>(istream& is, Task& task) {
    is.read(reinterpret_cast<char*>(&task), sizeof(Task));
    return is;
}

Exam::Exam() : taskCount(0) { }

bool Exam::addTask(const Task& task) {
    if (taskCount < MAX_TASKS) {
        tasks[taskCount++] = task;
        return true;
    }
    return false;
}

int Exam::getMaxPoints() const {
    int total = 0;
    for (int i = 0; i < taskCount; i++) {
        total += tasks[i].getPoints();
    }
    return total;
}

bool Exam::writeToFile(const char* filename) const {
    ofstream ofs(filename, ios::binary);
    if (!ofs)
        return false;

    ofs.write(reinterpret_cast<const char*>(&taskCount), sizeof(taskCount));

    for (int i = 0; i < taskCount; i++) {
        ofs.write(reinterpret_cast<const char*>(&tasks[i]), sizeof(Task));
    }
    ofs.close();
    return true;
}

bool Exam::readFromFile(const char* filename) {
    ifstream ifs(filename, ios::binary);
    if (!ifs)
        return false;

    ifs.read(reinterpret_cast<char*>(&taskCount), sizeof(taskCount));
    if (taskCount > MAX_TASKS) {
        taskCount = MAX_TASKS;
    }

    for (int i = 0; i < taskCount; i++) {
        ifs.read(reinterpret_cast<char*>(&tasks[i]), sizeof(Task));
    }
    ifs.close();
    return true;
}

void Exam::conductExam() {
    cout << "Conducting exam:\n";
    int earnedPoints = 0;
    for (int i = 0; i < taskCount; i++) {
        cout << "Task " << (i + 1) << ": " << tasks[i].getCondition() << endl;
        cout << "Answer (a, b, c, d): ";
        char answer;
        cin >> answer;
        if (answer == tasks[i].getCorrectAnswer()) {
            earnedPoints += tasks[i].getPoints();
        }
    }
    cout << "You earned " << earnedPoints << " points out of a total of " << getMaxPoints() << " possible points." << endl;
}