#pragma once

namespace TextCensorerConstants {
    constexpr int LETTERS_COUNT = 26;
};

class TextCensorer {
private:
    bool forbiddenLetters[TextCensorerConstants::LETTERS_COUNT] = {  };

    void printLetter(char a) const;
public:
    void addLetter(char a);
    void print(const char* str) const;
};