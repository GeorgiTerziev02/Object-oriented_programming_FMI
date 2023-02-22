#include <iostream>

int check(const int* nums, char s, int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (nums[i] > (int)s) count++;
	}
	return count;
}

int main() {
	int N;
	std::cin >> N;

	int* nums = new int[N];
	for (int i = 0; i < N; i++) {
		std::cin >> nums[i];
	}

	char s;
	std::cin >> s;
	std::cout << check(nums, s, N);

	return 0;
}