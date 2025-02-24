#include <iostream>

union IPv4Address {
	unsigned int address;
	unsigned char octets[4]; // [sizeof(address)]
};

void printIpAddress(const IPv4Address& ipAddress) {
	for (size_t i = 0; i < 4; i++) {
		std::cout << (int)ipAddress.octets[i];
		if (i != 3) {
			std::cout << ".";
		}
	}
}

int main() {
	IPv4Address myAddress;
	myAddress.address = 16777343;

	printIpAddress(myAddress);
}