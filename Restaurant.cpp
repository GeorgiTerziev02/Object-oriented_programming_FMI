#include "Restaurant.h"

Restaurant::Restaurant(size_t productsCount) {
	products=VectorOfStrings(productsCount);
}
void Restaurant::addProduct(const char* product) {
	MyString newProduct(product);
	products.pushBack(newProduct);
}
int Restaurant::receiveOrder(const Order& order) {
	if (isThereAnOrder)
		std::cout << "There is ongoing order" << std::endl;
		return -1;
	if (products.getSize() != order.productsCount)
		throw "Invalid order";
	for (int i = 0; products.getSize(); i++) {
		bool isCorrectOrder = true;
		for (int j = 0; products.getSize(); j++) {
			if (products[i] != order.products[j])
				isCorrectOrder = false;
		}
		if (!isCorrectOrder)
			throw "invalid Order";
	}
	this->order = order;
	isThereAnOrder = true;
	return products.getSize() * 10;
}

const MyString& Restaurant::getName()const {
	return name;
}