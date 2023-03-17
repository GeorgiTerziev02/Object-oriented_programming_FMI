#include <iostream>
#pragma warning(disable : 4996)

unsigned int strLen(const char* s)
{
    unsigned int count = 0;
    while (*s != '\0')
    {
        count++;
        s++;
    }
    return count;
}

char* strCopy(char* destination, const char* source) {
    if (destination == nullptr) {
        return NULL;
    }

    char *ptr = destination;

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;
}

class Teacher {
private:
    char* name;
    int namelength;
    int age;
    int expirience;
public:
    Teacher() : age(0),expirience(0) {
        name = new char[1];
        name[0] = '\0';
    }
    Teacher(const char* name,int age,int expirience) {
        this->namelength = strLen(name);
        this->name = new char[this->namelength + 1];
        strCopy(this->name, name);
        this->age = age;
        this->expirience=expirience;
    }
    
    const char* getName() const  {
        return this->name;
    }
    
    int  getAge() const {
        return this->age;
    }
    
    int  getNameLength() const {
        return this->namelength;
    }

    int getExp() const {
        return this->expirience;
    }

    void setName(const char* name) {
        delete[] this->name;
        this->namelength = strLen(name);
        this->name = new char[this->namelength + 1];
        strCopy(this->name, name);
    }

    void setAge(int age) {
        this->age = age;
    }

    void setExp(int expirience) {
        this->expirience;
    }

    ~Teacher()
    {
        delete[] this->name;
    }
};

int main()
{
    Teacher teacher("Gospodinov", 58, 30); 
    char* teacherName = new char[teacher.getNameLength()+1];
    strCopy(teacherName, teacher.getName());
    std::cout << "Teacher:" << std::endl;
    std::cout << teacher.getName() << " " << teacher.getAge() << " " << teacher.getExp();

}
