#include <iostream>
#pragma warning(disable : 4996)
class Teacher {
private:
    char* name;
    int namelength;
    int age;
    int expirience;
public:
    Teacher() : age(0),expirience(0) {
    }
    Teacher(const char* name,int namelength,int age,int expirience) {
        this->namelength=namelength;
        this->name = new char[namelength + 1];
        strcpy(this->name, name);
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

    void setName(char* name,int nameLength) {
        delete[] this->name;
        this->namelength = namelength;
        this->name = new char[namelength + 1];
        strcpy(this->name, name);
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
    Teacher teacher("Gospodinov", 11, 58, 30); 
    char* teacherName = new char[teacher.getNameLength()+1];
    strcpy(teacherName, teacher.getName());
    std::cout << "Teacher:" << std::endl;
    std::cout << teacher.getName() << " " << teacher.getAge() << " " << teacher.getExp();

}
