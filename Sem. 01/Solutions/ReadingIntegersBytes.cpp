#include <iostream>

int main() {
	int a = 412288; // hex - 00 06 4A 80
	unsigned char* ptr = (unsigned char*) &a;

	// print every byte of int as number(0 - 255) reversed
	std::cout << (int) (* ptr) << std::endl;	// 128 = 80 in hex  	// 8*16 + 0.1
	std::cout << (int) (* (ptr + 1)) << std::endl;	// 74  = 4A in hex	// 4*16 + 10*1
	std::cout << (int) (* (ptr + 2)) << std::endl;	// 06  = 06 in hex	// 0*16 + 6*1
	std::cout << (int) (* (ptr + 3)) << std::endl;  // 00  = 00 in hex	// 0*16 + 0*1
}
