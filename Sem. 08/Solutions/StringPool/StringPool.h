#pragma once

namespace StringPoolConstants {
	const unsigned char SMALL_STRING_MAX_LENGTH = 64;
	const unsigned char INITIAL_CAPACITY = 4;
}

class StringPool {
private:
	class SmallString {
	private:
		char data[StringPoolConstants::SMALL_STRING_MAX_LENGTH + 1];
		size_t refsCount = 1;
	public:
		SmallString(const char* str);
		const char* c_str() const;
		const size_t getRefsCount() const;

		bool operator==(const SmallString& other) const;
		bool operator<(const SmallString& other) const;		
		friend class StringPool;
	};
	// should be a friend of the StringPool so that
	// we can access the SmallString
	friend int compare(const StringPool::SmallString& lhs, const StringPool::SmallString& rhs);

	SmallString** data;
	size_t size = 0;
	size_t capacity = 0;

	void resize();
public:
	StringPool();
	StringPool(const StringPool& other);
	StringPool& operator=(const StringPool& other);
	~StringPool();

	size_t getSize() const;
	void insert(const SmallString& str);
	long long find(const SmallString& str) const;
	void removeAt(size_t index);

	const SmallString& operator[](size_t) const;

private:
	void copyFrom(const StringPool& other);
	void free();
};