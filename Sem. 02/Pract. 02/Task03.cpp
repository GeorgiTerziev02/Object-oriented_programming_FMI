#include <iostream>
#include <fstream>

const int MAX_STRING_LENGTH = 100;
const char ERROR_MESSAGE[] = "Error";
const char PLACEHOLDER_FILE_NAME[] = "placeholder.txt";
const char TEMPLATE_FILE_NAME[] = "template.txt";
const char RESULT_FILE_NAME[] = "result.txt";

struct Placeholder {
    char key[MAX_STRING_LENGTH];
    char value[MAX_STRING_LENGTH];
};

void preparePlaceholders() {
    std::ofstream out(PLACEHOLDER_FILE_NAME);
    if (!out.is_open()) {
        return;
    }

    out << "title Veliki" << std::endl;
    out << "recipient_name Pop Armeniya" << std::endl;
    out << "message Iskam da se oplacha!!!" << std::endl;
    out << "sender_name FMI-student";

    out.close();
}

void prepareTemplate() {
    std::ofstream out(TEMPLATE_FILE_NAME);
    if (!out.is_open()) {
        return;
    }

    out << "Dear, {title} {recipient_name}." << std::endl;
    out << "{message}" << std::endl << std::endl;
    out << "Sincerely," << std::endl;
    out << "{sender_name}" << std::endl;

    out.close();
}

size_t strLen(const char* arr) {
    size_t count = 0;
    while (arr[count] != '\0') {
        count++;
    }

    return count;
}

bool strCmp(const char* str1, const char* str2) {
    size_t str1Length = strLen(str1);
    size_t str2Length = strLen(str2);
    if (str1Length != str2Length) {
        return false;
    }

    for (size_t i = 0; i < str1Length; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}

size_t getCharOccurrences(std::ifstream& in, char ch) {
    size_t initialPosition = in.tellg();
    in.seekg(initialPosition, std::ios::beg);

    size_t occurrences = 0;
    char current;

    while (true) {
        in.get(current);

        if (in.eof()) {
            break;
        }

        if (current == ch) {
            occurrences++;
        }
    }

    in.clear();
    in.seekg(initialPosition, std::ios::beg);

    return occurrences;
}

size_t getLinesCount(const char fileName[]) {
    std::ifstream in(fileName);

    if (!in.is_open()) {
        std::cout << ERROR_MESSAGE;
        return 0;
    }

    size_t result = getCharOccurrences(in, '\n') + 1;
    in.close();

    return result;
}

void getPlaceholdersFromFile(
    Placeholder* placeholders,
    std::ifstream& in,
    const size_t placeholdersCount
) {
    for (size_t i = 0; i < placeholdersCount; i++) {
        // up to the ' ' to read the name
        in.getline(placeholders[i].key, MAX_STRING_LENGTH, ' ');
        // up to the end of the line to read the value
        in.getline(placeholders[i].value, MAX_STRING_LENGTH, '\n');
    }
}

void writeReplacementFromPlaceholder(
    const char* name,
    std::ofstream& out,
    const Placeholder* placeholders,
    const size_t placeholdersCount
) {
    for (size_t i = 0; i < placeholdersCount; i++) {
        if (strCmp(placeholders[i].key, name)) {
            out << placeholders[i].value;
        }
    }
}

void readPlaceholders(Placeholder*& placeholders, size_t& placeholdersCount) {
    placeholdersCount = getLinesCount(PLACEHOLDER_FILE_NAME);
    std::ifstream in(PLACEHOLDER_FILE_NAME);
    if (!in.is_open()) {
        std::cout << ERROR_MESSAGE;
        return;
    }

    placeholders = new Placeholder[placeholdersCount];
    getPlaceholdersFromFile(
        placeholders,
        in,
        placeholdersCount
    );

    in.close();
}

void replacePlaceholders() {
    std::ifstream in(TEMPLATE_FILE_NAME);
    std::ofstream out(RESULT_FILE_NAME);
    if (!in.is_open() || !out.is_open()) {
        std::cout << ERROR_MESSAGE;
        return;
    }

    Placeholder* placeholders = nullptr;
    size_t placeholdersCount = 0;
    readPlaceholders(placeholders, placeholdersCount);

    char current;
    while (true) {
        in.get(current);
        if (in.eof()) {
            break;
        }

        if (current == '{') {
            char name[MAX_STRING_LENGTH];
            in.getline(name, MAX_STRING_LENGTH, '}');

            writeReplacementFromPlaceholder(
                name,
                out,
                placeholders,
                placeholdersCount
            );

            continue;
        }

        out << current;
    }

    in.close();
    out.close();
    delete[] placeholders;
}

int main() {
    preparePlaceholders();
    prepareTemplate();

    replacePlaceholders();
}