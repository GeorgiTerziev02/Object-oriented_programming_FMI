#include "StringPool.h"
#include <iostream>

#pragma warning(disable:4996)

// set data to node
void StringPool::StringNode::allocateData(const char* str) {
	data = new char[strlen(str) + 1];
	strcpy(data, str);
}

void StringPool::resize() {
	// TODO: more usefull way to calculate capcity
	StringNode* newNodes = new StringNode[capacity *= 2]{};
	for (size_t i = 0; i < size; i++) {
		newNodes[i] = nodes[i];
	}

	delete[] nodes;
	nodes = newNodes;
}

StringPool::StringPool() {
	nodes = new StringNode[capacity];
}

StringPool::~StringPool() {
	for (size_t i = 0; i < size; i++) {
		delete[] nodes[i].data;
	}
	delete[] nodes;
}

const char* StringPool::getString(const char* str) {
	int index = -1;
	bool found = lowerBound(str, index);
	if (found) {
		nodes[index].referenceCount++;
		return nodes[index].data;
	}

	return insert(str, index + 1);
}

void StringPool::removeString(const char* str) {
	int index = -1;
	bool found = lowerBound(str, index);
	if (!found) {
		throw std::exception("String not found");
	}

	nodes[index].referenceCount--;
	if (nodes[index].referenceCount == 0) {
		removeStringFromPool(index);
	}
}

const char* StringPool::insert(const char* str, size_t index) {
	if (index > size) {
		throw std::out_of_range("StringPool::insert invalid index!");
	}

	if (size == capacity) {
		resize();
	}

	for (int i = size - 1; i >= (int)index; i--) {
		// here we need op=
		// imagine if we do free and copy on every step for the StringNode
		// thats why we use default op=
		nodes[i + 1] = nodes[i];
	}

	nodes[index].allocateData(str);
	nodes[index].referenceCount = 1;

	++size;
	return nodes[index].data;
}

void StringPool::removeStringFromPool(int index) {
	if (size <= index) {
		throw std::out_of_range("Index out range");
	}

	delete[] nodes[index].data;

	for (size_t i = index; i < size - 1; i++) {
		// here we need op=
		// imagine if we do free and copy on every step for the StringNode
		// thats why we use default op=
		nodes[i] = nodes[i + 1];
	}
	nodes[size - 1].data = nullptr;
	nodes[size - 1].referenceCount = 0;
	size--;
}


bool StringPool::lowerBound(const char* str, int& index) {
	int left = 0;
	int right = size - 1;
	int leftmostIndex = -1;

	while (left <= right) {
		int mid = (right - left) / 2 + left;
		int cmp = strcmp(nodes[mid].data, str);

		if (cmp == 0) {
			index = mid;
			return true;
		}
		else if (cmp > 0) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			leftmostIndex = mid;
		}
	}

	index = leftmostIndex;
	return false;
}

void StringPool::print() const {
	for (size_t i = 0; i < size; i++) {
		std::cout << "We have: " << nodes[i].data << " " << nodes[i].referenceCount << " times" << std::endl;
	}
	std::cout << std::endl;
}
