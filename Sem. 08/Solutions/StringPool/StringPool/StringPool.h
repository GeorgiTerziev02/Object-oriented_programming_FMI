#pragma once

class StringPool {
private:
	static constexpr int INITIAL_CAPACITY = 8;

	struct StringNode {
		char* data = nullptr;
		size_t referenceCount = 0;

		// This is internal class we can mark the operators as default (cc is deleted)
		// why?
		// as an internal class => only I can create create instances inside me
		// so I am the owner of these resources, I can delete them
		StringNode() = default;
		StringNode(const StringNode&) = delete;
		StringNode& operator=(const StringNode&) = default;
		~StringNode() = default;

		void allocateData(const char* str);
	};

	StringNode* nodes = nullptr;
	size_t size = 0;
	size_t capacity = INITIAL_CAPACITY;

	bool lowerBound(const char* str, int& index);
	const char* insert(const char* str, size_t index);
	void resize();
	void removeStringFromPool(int index);
public:
	StringPool();
	StringPool(const StringPool& pool) = delete;
	StringPool& operator=(const StringPool& other) = delete;
	~StringPool();

	const char* getString(const char* str);
	void removeString(const char* str);

	void print() const;
};
