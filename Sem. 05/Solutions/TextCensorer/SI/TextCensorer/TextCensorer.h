#pragma once

class TextCensorer {
private:
    bool (*shouldCensor)(char) = nullptr;

public:
    TextCensorer(bool (*shouldCensor)(char));

    void print(const char* str) const;
    void print(char a) const;
};