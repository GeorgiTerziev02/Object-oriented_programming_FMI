#include "CommandExecutor.h"

CommandExecutor::~CommandExecutor() {
    while (!toExecute.empty()) {
        delete toExecute.peek();
        toExecute.pop();
    }
    while (!executed.empty()) {
        delete executed.peek();
        executed.popBack();
    }

}

void CommandExecutor::add(VectorCommand* c) {
    toExecute.push(c);
}

void CommandExecutor::execute();

void CommandExecutor::executeAll();

void CommandExecutor::();