#include <iostream>

constexpr int BUFFER_SIZE = 64;

int main() {
    int a;
    std::cin >> a; // leaves a '\n' or ' ' in the input stream
    char arr[BUFFER_SIZE];
    // cin.getline will read the left character in the input stream
    // => either arr will be empty string or will start with ' '
    // to fix => std::cin.ignore(); - to ignore one character in the input stream
    // std::cin.ignore(N); - to ignore N symbols
    // cin.getline reads until it finds '\n' or BUFFER_SIZE symbols
    // + 1 for the terminating '\0'
    std::cin.ignore();
    std::cin.getline(arr, BUFFER_SIZE + 1);
    std::cout << a << std::endl;
}