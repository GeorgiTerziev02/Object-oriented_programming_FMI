#pragma once

class SelfCounting {
private:
	static size_t createdInstances;
	static size_t livingInstances;

	int localTempVariable;
public:
	static size_t getLivingInstances();
	static size_t getCreatedInstances();

	SelfCounting();
	SelfCounting(const SelfCounting& other);
	~SelfCounting();
};