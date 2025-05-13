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

void CommandExecutor::execute() {
    if (toExecute.empty()) {
        return;
    }
    VectorCommand* c = toExecute.peek();
    c->execute();
    executed.pushBack(c);
    toExecute.pop();
}

void CommandExecutor::executeAll() {
    while (!toExecute.empty()) {
        execute();
    }
}

void CommandExecutor::undo() {
    if (executed.empty()) {
        return;
    }
    VectorCommand* c = executed.peek();
    c->undo();
    executed.popBack();
    delete c;
}