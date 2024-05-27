
#include "StringView.h"

StringView::StringView(const char* str): StringView(str, str + strlen(str)) { }

StringView::StringView(const MyString& str): start(str.c_str()), end(start + str.getLength()) { }

StringView::StringView(const char* start, const char* end) : start(start), end(end)  {
	if (start >= end) {
		throw std::runtime_error("Cannot create StringView. End pointer must be after Start pointer");
	}
}

size_t StringView::length() const {
	return end - start;
}

char StringView::operator[](size_t index) const {
	return start[index];
}

StringView StringView::substr(size_t fromIndex, size_t length) const {
	if (start + fromIndex + length > end) {
		throw std::logic_error("Error, resulting Substring out of view range");
	}

	return StringView(start + fromIndex, start + fromIndex + length);
}

std::ostream& operator<<(std::ostream& os, const StringView& view) {
	const char* iter = view.start;

	while (iter != view.end) {
		os << *iter;
		iter++;
	}

	return os;
}

int compare(const StringView& lhs, const StringView& rhs) {
	const char* lhsIter = lhs.start;
	const char* rhsIter = rhs.start;

	while (lhsIter != lhs.end && rhsIter != rhs.end) {
		if (*lhsIter != *rhsIter) {
			break;
		}

		lhsIter++;
		rhsIter++;
	}

	if (lhsIter == lhs.end && rhsIter == rhs.end) {
		return 0;
	}
	else if(lhsIter == lhs.end && rhsIter != rhs.end) {
		return -1;
	}
	else if(lhsIter != lhs.end && rhsIter == rhs.end) {
		return 1;
	}
	else {
		return *lhsIter - *rhsIter;
	}
}

bool operator<(const StringView& lhs, const StringView& rhs) {
	return compare(lhs, rhs) < 0;
}

bool operator<=(const StringView& lhs, const StringView& rhs) {
	return compare(lhs, rhs) <= 0;
}

bool operator>=(const StringView& lhs, const StringView& rhs) {
	return compare(lhs, rhs) >= 0;
}

bool operator>(const StringView& lhs, const StringView& rhs) {
	return compare(lhs, rhs) > 0;
}

bool operator==(const StringView& lhs, const StringView& rhs) {
	return compare(lhs, rhs) == 0;
}

bool operator!=(const StringView& lhs, const StringView& rhs) {
	return compare(lhs, rhs) != 0;
}
