#include "Containers/MyStack.hpp"
#include "Containers/MyQueue.hpp"
#include "Command/VectorCommand.h"

struct CommandExecutor {
private:
	MyQueue<VectorCommand*> toExecute;
	MyStack<VectorCommand*> executed;
public:
	CommandExecutor() = default;
	CommandExecutor(const CommandExecutor&) = delete;
	CommandExecutor& operator=(const CommandExecutor&) = delete;
	~CommandExecutor();

	void add(VectorCommand* c);
	void execute();
    void executeAll();
	void undo();
};