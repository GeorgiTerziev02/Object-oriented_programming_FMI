#include <iostream>
#include "Containers/IntVector.h"
#include "Command/VectorCommand.h"
#include "Command/SwapCommand.h"
#include "Command/SortCommand.h"
#include "CommandExecutor.h"

void print(const IntVector& v) {
	for (size_t i = 0; i < v.getSize(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

struct Factory {
public:
	static VectorCommand* create(IntVector& v, size_t commandNumber) {
		if (commandNumber == 1) {
            size_t from, to;
            std::cin >> from >> to;
            return new SwapCommand(v, from, to);
		}
		else if(commandNumber == 2) {
            return new SortCommand(v);
		}

        throw std::invalid_argument("Invalid command number");
	}
};

int main() {
	IntVector v;
	for (int i = 9; i >= 0; i--) {
		v.pushBack(i);
	}

	CommandExecutor ce;

	VectorCommand* vc1 = new SwapCommand(v, 4, 5);
	VectorCommand* vc2 = new SortCommand(v);

	ce.add(vc1);
	ce.add(vc2);
	print(v);
	ce.execute();
	print(v);
	ce.execute();
	print(v);
	ce.undo();
	print(v);
	ce.undo();
	print(v);
}