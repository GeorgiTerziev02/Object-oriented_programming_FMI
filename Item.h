#pragma once
class Item
{
private:
	bool availability;
	char* name;
	float price;
	size_t itemAmount = 0;

	void copyFrom(const Item& other);
	void free();
public:
	Item();
	Item(const char* name, bool availabilty, float);
	Item(const Item& other);
	Item& operator=(const Item& other);
	
	void itemCountIterator();
	void setName(const char* name);
	void setAvailability(bool availabilty);
	void setPrice(float price);

	size_t getItemCount()const;
	char* getName()const;
	bool getAvailability()const;
	float getPrice()const;

	~Item();
};

