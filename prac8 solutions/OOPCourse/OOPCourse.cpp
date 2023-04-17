#include <cstring>
#include "OOPCourse.h"

const short INITIAL_CAPACITY = 5;

void OOPcourse::copyStudents(Student ** const students, unsigned studentsCount, unsigned studentsCapacity) {
    _studentsCount = studentsCount;
    _studentsCapacity = studentsCapacity;
    _students = new Student *[_studentsCapacity];

    for (unsigned i = 0; i < _studentsCount; i++) {
        _students[i] = new Student(*(students[i]));
    }
}

void OOPcourse::copyGrades(Grade ** const grades, unsigned gradesCount, unsigned gradesCapacity) {
    _gradesCount = gradesCount;
    _gradesCapacity = gradesCapacity;
    _grades = new Grade *[_gradesCapacity];

    for (unsigned i = 0; i < _gradesCount; i++) {
        _grades[i] = new Grade(*(grades[i]));
    }
}

void OOPcourse::copyFrom(const OOPcourse &other) {
    copyStudents(other._students, other._studentsCapacity, other._studentsCapacity);
    copyGrades(other._grades, other._gradesCount, other._gradesCapacity);
}

void OOPcourse::freeStudents() {
    for (unsigned i = 0; i < _studentsCount; i++) {
        delete _students[i];
    }

    delete[] _students;
    _studentsCapacity = _studentsCount = 0;
}

void OOPcourse::freeGrades() {
    for (unsigned i = 0; i < _gradesCount; i++) {
        delete _grades[i];
    }

    delete[] _grades;
    _gradesCapacity = _gradesCount = 0;
}

void OOPcourse::free() {
    freeStudents();
    freeGrades();
}

void OOPcourse::resizeStudents() {
    _studentsCapacity *= 2;
    Student **temp = new Student *[_studentsCapacity];
    for (unsigned i = 0; i < _studentsCount; ++i) {
        temp[i] = _students[i];
    }

    delete[] _students;
    _students = temp;
}

void OOPcourse::resizeGrades() {
    _gradesCapacity *= 2;
    Grade **temp = new Grade *[_gradesCapacity];
    for (unsigned i = 0; i < _gradesCount; ++i) {
        temp[i] = _grades[i];
    }

    delete[] _grades;
    _grades = temp;
}

OOPcourse::OOPcourse() : OOPcourse("") {}

OOPcourse::OOPcourse(const OOPcourse &other) {
    copyFrom(other);
}

OOPcourse &OOPcourse::operator=(const OOPcourse &other){
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

OOPcourse::~OOPcourse() {
    free();
}

OOPcourse::OOPcourse(const char *teacherName)
    : OOPcourse(teacherName, 0, "", "", "") {}

OOPcourse::OOPcourse(const char *teacherName, const char *assistantOneName)
    : OOPcourse(teacherName, 1, assistantOneName, "", "") {}

OOPcourse::OOPcourse(const char *teacherName, const char *assistantOneName, const char *assistantTwoName)
    : OOPcourse(teacherName, 2, assistantOneName, assistantTwoName, "") {}

OOPcourse::OOPcourse(const char *teacherName, const char *assistantOneName, const char *assistantTwoName, const char *assistantThreeName)
    : OOPcourse(teacherName, 3, assistantOneName, assistantTwoName, assistantThreeName) {}

OOPcourse::OOPcourse(const char *teacherName, unsigned int assistantCount,
                       const char *assistantOneName,
                       const char *assistantTwoName,
                       const char *assistantThreeName) {
    _teacherName.setName(teacherName);
    _assistantCount = assistantCount;
    _assistantNames[0].setName(assistantOneName);
    _assistantNames[1].setName(assistantTwoName);
    _assistantNames[2].setName(assistantThreeName);

    _studentsCount = 0;
    _studentsCapacity = INITIAL_CAPACITY;
    _students = new Student *[_studentsCapacity];

    _gradesCount = 0;
    _gradesCapacity = INITIAL_CAPACITY;
    _grades = new Grade *[_gradesCapacity];
}

unsigned OOPcourse::getStudentIndexByFac(unsigned int studentFac) {
    for (unsigned i = 0; i < _studentsCount; ++i) {
        if (_students[i]->getFac() == studentFac) {
            return i;
        }
    }

    throw "Student not found!";
}

void OOPcourse::addStudent(const char *studentName, unsigned studentFac) {
    if (_studentsCount >= _studentsCapacity) {
        resizeStudents();
    }

    _students[_studentsCount++] = new Student(studentName, studentFac);
}

void OOPcourse::addGrade(unsigned studentFac, const char *assignmentName, unsigned grade, const char *teacherName) {
    if (_gradesCount >= _gradesCapacity) {
        resizeGrades();
    }
    try {
        Student &student = *_students[getStudentIndexByFac(studentFac)];
        student.addGrade();

        if (doesStudentHasGradeOnAssignment(studentFac, assignmentName, teacherName)) {
            throw "Student is already graded! on this assignment";
        }
    }
    catch (const char *msg) {
        // handle?
        throw;
    }

    _grades[_gradesCount++] = new Grade(assignmentName, teacherName, studentFac, grade);
}

double OOPcourse::getAverageForCourse() const {
    double gradesTotal = 0;
    for (int i = 0; i < _gradesCount; ++i) {
        gradesTotal += _grades[i]->getValue();
    }

    return gradesTotal / _gradesCount;
}

void OOPcourse::removeStudentAtIndex(unsigned index) {
    if (index >= _studentsCount) {
        throw "Invalid index!";
    }

    delete _students[index];
    _students[index] = _students[_studentsCount - 1];
    _students[--_studentsCount] = nullptr;
}

void OOPcourse::removeGradeAtIndex(unsigned index) {
    if (index >= _gradesCount) {
        throw "Invalid index!";
    }

    delete _grades[index];
    _grades[index] = _grades[_gradesCount - 1];
    _grades[--_gradesCount] = nullptr;
}

void OOPcourse::removeGradesByStudentFac(unsigned studentFac) {
    for (int i = 0; i < _gradesCount;) {
        if (_grades[i]->getStudentFac() == studentFac) {
            removeGradeAtIndex(i);
        }
        else ++i;
    }
}

void OOPcourse::removeStudent(unsigned int studentFac) {
    try {
        removeGradesByStudentFac(studentFac);
        removeStudentAtIndex(getStudentIndexByFac(studentFac));
    }
    catch (const char *msg) {
//         handle?
        throw;
    }
}

bool areAssignmentMatching(const Grade &grade, const char *assignmentName) {
    return strcmp(grade.getAssignmentName(), assignmentName) == 0;
}

bool areTeacherMatching(const Grade &grade, const char *teacherName) {
    return strcmp(grade.getTeacherName(), teacherName) == 0;
}

double OOPcourse::getAverageByCriteria(bool (*compFunc)(const Grade &grade, const char *name), const char *name) const {
    double gradesTotal = 0;
    double curGradesCount = 0;
    for (int i = 0; i < _gradesCount; ++i) {
        if (compFunc(*_grades[i], name)) {
            gradesTotal += _grades[i]->getValue();
            curGradesCount++;
        }
    }

    return gradesTotal / curGradesCount;
}

double OOPcourse::getAverageGradePerTask(const char *assignmentName) const {
    return getAverageByCriteria(areAssignmentMatching, assignmentName);
}

double OOPcourse::getAverageFromTeacher(const char *teacherName) const {
    return getAverageByCriteria(areTeacherMatching, teacherName);
}

bool OOPcourse::doesStudentHasGradeOnAssignment(unsigned studentFac, const char *assignmentName, const char *teacherName) {
    try {
        getGrade(studentFac, assignmentName, teacherName);
    }
    catch(const char *msg) {
        return false;
    }

    return true;
}

Grade &OOPcourse::getGrade(unsigned studentFac, const char *assignmentName, const char *teacherName) {
    for (int i = 0; i < _gradesCount; ++i) {
        Grade &curGrade = *_grades[i];

        if (curGrade.getStudentFac() != studentFac) {
            continue;
        }

        if (strcmp(curGrade.getAssignmentName(), assignmentName) != 0) {
            continue;
        }

        if (strcmp(curGrade.getTeacherName(), teacherName) != 0) {
            continue;
        }

        return curGrade;
    }

    throw "Grade not found!";
}

void OOPcourse::changeGrade(unsigned studentFac, const char *assignmentName, unsigned grade, const char *teacherName) {
    try {
        Grade &curGrade = getGrade(studentFac, assignmentName, teacherName);
        curGrade.setValue(grade);
    }
    catch (const char *msg) {
        // handle

        throw;
    }
}
