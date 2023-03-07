#include <iostream>
#include <fstream>

const int MAX_STRING_LENGTH = 100;
const char ERROR_MESSAGE[] = "Error";
const char PLACEHOLDER_FILE_NAME[] = "placeholder.txt";
const char TEMPLATE_FILE_NAME[] = "template.txt";
const char RESULT_FILE_NAME[] = "result.txt";

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
    char** placeholderNames,
    char** placeholderValues,
    std::ifstream& placeholder,
    const size_t placeholdersCount
) {
    for (size_t i = 0; i < placeholdersCount; i++) {
        // up to the ' ' to read the name
        placeholder.getline(placeholderNames[i], MAX_STRING_LENGTH, ' ');
        // up to the end of the line to read the value
        placeholder.getline(placeholderValues[i], MAX_STRING_LENGTH, '\n');
    }
}

void writeReplacementFromPlaceholder(
    const char* name,
    std::ofstream& out,
    const char* const* placeholderNames,
    const char* const* placeholderValues,
    const size_t placeholdersCount
) {
    for (size_t i = 0; i < placeholdersCount; i++) {
        if (strCmp(placeholderNames[i], name)) {
            out << placeholderValues[i];
        }
    }
}

void initPlaceholders(char**& placeholderNames, char**& placeholderValues, const size_t placeholdersCount) {
    placeholderNames = new char* [placeholdersCount];
    placeholderValues = new char* [placeholdersCount];

    for (size_t i = 0; i < placeholdersCount; i++) {
        placeholderNames[i] = new char[MAX_STRING_LENGTH];
        placeholderValues[i] = new char[MAX_STRING_LENGTH];
    }
}

void deletePlaceholders(char** placeholderNames, char** placeholderValues, size_t placeholdersCount) {
    for (size_t i = 0; i < placeholdersCount; i++) {
        delete[] placeholderNames[i];
        delete[] placeholderValues[i];
    }

    delete[] placeholderNames;
    delete[] placeholderValues;
}

void readPlaceholders(char**& placeholderNames, char**& placeholderValues, size_t& placeholdersCount) {
    placeholdersCount = getLinesCount(PLACEHOLDER_FILE_NAME);
    std::ifstream placeholder(PLACEHOLDER_FILE_NAME);
    if (!placeholder.is_open()) {
        std::cout << ERROR_MESSAGE;
        return;
    }

    initPlaceholders(placeholderNames, placeholderValues, placeholdersCount);
    getPlaceholdersFromFile(
        placeholderNames,
        placeholderValues,
        placeholder,
        placeholdersCount
    );

    placeholder.close();
}

void replacePlaceholders() {
    std::ifstream in(TEMPLATE_FILE_NAME);
    std::ofstream out(RESULT_FILE_NAME);

    if (!in.is_open() || !out.is_open()) {
        std::cout << ERROR_MESSAGE;
        return;
    }

    char** placeholderNames = nullptr;
    char** placeholderValues = nullptr;
    size_t placeholdersCount = 0;

    readPlaceholders(placeholderNames, placeholderValues, placeholdersCount);
    //for (size_t i = 0; i < placeholdersCount; i++){
    //    std::cout << placeholderNames[i] << " " << placeholderValues[i] << std::endl;
    //}

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
                placeholderNames,
                placeholderValues,
                placeholdersCount
            );

            continue;
        }

        out << current;
    }
    in.close();
    out.close();

    deletePlaceholders(placeholderNames, placeholderValues, placeholdersCount);
}

int main()
{
    preparePlaceholders();
    prepareTemplate();

    replacePlaceholders();
}