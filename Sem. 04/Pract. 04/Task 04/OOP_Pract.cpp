#include <iostream>
#include "Secret.h"

int main()
{
	auto taskDesc = "A task description.";
	auto taskDesc2 = "Second task";
	auto password = "123ili";
	Secret task(taskDesc, password);

	std::cout << task.getLoginFails() << std::endl;
	std::cout << task.getTask("123ili") << std::endl;
	task.setTask(taskDesc2, "123ili");
	std::cout << task.getTask("123ili") << std::endl;
	task.setPassword("123123", "123");
	std::cout << task.getLoginFails() << std::endl;
	task.setPassword("123123", "123ili");
	std::cout << task.getLoginFails() << std::endl;
	std::cout << task.getTask("123123");
}