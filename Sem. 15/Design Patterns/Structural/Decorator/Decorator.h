#pragma once
#include <string>
#include <iostream>

class DataSource {
	std::string data;
public:
	virtual void setData(const std::string& data) { this->data = data; }
	virtual const std::string& readData() const { return data; }
	virtual ~DataSource() = default;
};

class DataSourceDecorator : DataSource {
protected:
	DataSource* wrappedObject;
public:
	DataSourceDecorator(DataSource* obj) : wrappedObject(obj) { }

	void setData(const std::string& data) override {
		wrappedObject->setData(data);
	}

	const std::string& readData() const override {
		return wrappedObject->readData();
	}
};

class ConsoleLoggerDecorator : public DataSourceDecorator {
public:
	void setData(const std::string& data) override {
		std::cout << "We are setting data" << std::endl;
		return DataSourceDecorator::setData(data);
	}

	const std::string& readData() const override {
		std::cout << "We are reading data" << std::endl;
		return DataSourceDecorator::readData();
	}
};

class TestDecorator : public ConsoleLoggerDecorator {
public:
	void setData(const std::string& data) override {
		std::string newString = data + "abcde";
		return ConsoleLoggerDecorator::setData(newString);
	}

	const std::string& readData() const override {
		return ConsoleLoggerDecorator::readData();
	}
};