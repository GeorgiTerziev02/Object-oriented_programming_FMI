#include "SortedCollection.h"

int SortedCollection::lowerBound(int n) const {
	int left = 0;
	int right = size - 1;
	int indexToReturn = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (data[mid] == n) {
			indexToReturn = mid;
			right = mid - 1;
		}
		else if (data[mid] < n) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return indexToReturn;
}

int SortedCollection::upperBound(int n) const {
	int left = 0;
	int right = size - 1;
	int indexToReturn = -1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (data[mid] == n) {
			indexToReturn == mid;
			left = mid + 1;
		}
		else if (data[mid] > n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return indexToReturn;
}

void SortedCollection::add(int n) {
	if (size == capacity) {
		resize(2 * size);
	}

	int index = size;

	while (index != 0 && data[index - 1] > n) {
		data[index] = data[index - 1];
		index--;
	}

	data[index] = n;
	size++;
}

void SortedCollection::remove(int n) {
	int index = lowerBound(n);
	if (index == -1) {
		return;
	}

	for (size_t i = index; i < size - 1; i++) {
		data[i] = data[i + 1];
	}
	--size;
}

size_t SortedCollection::count(int n) const {
	int leftIndex = lowerBound(n);
	if (leftIndex == -1) {
		return 0;
	}

	int rightIndex = upperBound(n);
	return rightIndex - leftIndex + 1;
}

bool SortedCollection::contains(int n) const {
	return lowerBound(n) != -1;
}
