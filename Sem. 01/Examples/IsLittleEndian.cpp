#include <stdint.h>

bool isLittleEndian() {
    union {
        unsigned int i;
        char c[sizeof(i)];
    } test;
    test.i = 1;
    
    return test.i;
}