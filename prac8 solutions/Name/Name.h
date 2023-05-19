#pragma once

class Name {
private:
    char *_value;
    unsigned _size;

    void copyName(const char *value, unsigned size);
    void copyFrom(const Name &other);
    void free();

public:
    Name();
    Name(const Name &other);
    Name &operator=(const Name &other);
    ~Name();

    const char *getName() const;
    void setName(const char *value);
};
