#pragma once

// https://www.geeksforgeeks.org/binary-search-preferred-ternary-search/

// All classes can be template

class SearchStrategy {
public:
	virtual int execute(const int* arr, int size, int target) = 0;
	virtual SearchStrategy* clone() const = 0;
	virtual ~SearchStrategy() = default;
};

class BinarySearchStrategy : public SearchStrategy {
public:
	int execute(const int* arr, int size, int target) override {
		int left = 0;
		int right = size - 1;

		while (left <= right) {
			// handles the case when the sum
			// of left + right > INT_MAX
			int mid = left + (right - left) / 2;

			if (arr[mid] == target)
				return mid;
			else if (arr[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}

		return -1;
	}
	
	SearchStrategy* clone() const override {
		return new BinarySearchStrategy(*this);
	}
};

class TernarySearchStrategy : public SearchStrategy {
public:
	int execute(const int* arr, int size, int target) override {
		int left = 0;
		int right = size - 1;

		while (left <= right)
		{
			int mid1 = left + (right - left) / 3; // 2 * left + right
			int mid2 = right - (right - left) / 3; // 2*right + left

			if (arr[mid1] == target)
				return mid1;

			if (arr[mid2] == target)
				return mid2;

			if (target < arr[mid1]) {
				right = mid1 - 1;
			}
			else if (target > arr[mid2]) {
				left = mid2 + 1;
			}
			else {
				left = mid1 + 1;
				right = mid2 - 1;
			}
		}

		return -1;
	}

	SearchStrategy* clone() const override {
		return new TernarySearchStrategy(*this);
	}
};

class ArraySeacher {
private:
	SearchStrategy* searchStrategy = nullptr;

public:
	ArraySeacher(const SearchStrategy& searchStrategy) : searchStrategy(searchStrategy.clone()) {}
	ArraySeacher(const ArraySeacher&) = delete;
	ArraySeacher& operator=(const ArraySeacher&) = delete;
	~ArraySeacher() { delete searchStrategy; }

	void setStrategy(const SearchStrategy& searchStrategy) {
		delete this->searchStrategy;
		this->searchStrategy = searchStrategy.clone();
	}

	int search(const int* arr, int size, int target) {
		// some logic
		int index = searchStrategy->execute(arr, size, target);
		// more logic
		return index; // not required to return the index
	}
};

