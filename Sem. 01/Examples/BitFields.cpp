#include <iostream>

struct S1 {
    // three-bit unsigned field, allowed values are 0...7
    unsigned int b : 3;
    // if the value exceeds 7, the result is implementation-defined
};

struct S2 {
    // will usually occupy 2 bytes:
    unsigned char b1 : 3; // 1st 3 bits (in 1st byte) are b1
    unsigned char : 2; // next 2 bits (in 1st byte) are blocked out as unused
    unsigned char b2 : 6; // 6 bits for b2 - doesn't fit into the 1st byte => starts a 2nd
    unsigned char b3 : 2; // 2 bits for b3 - next (and final) bits in the 2nd byte
};
// s2 comment
// looks like --- 1110000011110111
// breakdown is:  └┬┘├┘└┬┘└─┬──┘└┤
//                b1 u  a   b2  b3

struct S3 {
    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 5 bits: unused
    // 2 bits: value of b2
    // 6 bits: unused
    unsigned char b1 : 3;
    unsigned char :0; // start a new byte !!!
    unsigned char b2 : 2;
};
