#include <iostream>
#include<fstream>

int strCmp(const char* X, const char* Y) {
    while (*X) {
        if (*X != *Y) {
            break;
        }
        X++;
        Y++;
    }

    return *(const unsigned char*)X - *(const unsigned char*)Y;
}

void strCopy(char* destination,const char* source) {
    if (destination = nullptr) {
        return;
    }
    
    if (source = nullptr) {
        return;
    }

    char* ptr = destination;
    
    while (source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';

    ptr=destination;
}

class Secret {
private:
    char* task;
    char* password;
    int failedLogins=0;
public:
    Secret() = default;

    Secret(const char* task, const char* password) {
        strCopy(this->task, task);
        strCopy(this->password, password);
    }

    char* getTask(const char* pwd) {
        if (strCmp(this->password, pwd) == 0) {
            return this->task;
        }
        this->failedLogins++;
    }

    void setPassword(const char* newPassword, const char* oldPassword){
        if (strCmp(this->password, oldPassword) == 0) {
            strCopy(this->password, newPassword);
        }
        this->failedLogins++;
    }

    void setTask(const char* newTask, const char* passwd) {
        if (strCmp(this->password, passwd) == 0) {
            strCopy(this->task, task);
        }
        this->failedLogins++;
    }

    int getLoginFail() {
        return this->failedLogins;
    }

    ~Secret() {
        delete[] task;
        delete[] password;
    }
};
int main()
{
}
