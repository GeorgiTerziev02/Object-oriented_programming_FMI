#pragma once
#include "VectorCommand.h"
#include <iostream>

class SwapCommand : public VectorCommand {
	size_t from, to;
    // It will be good to have some isExecuted logic
    // because we should not execute undo() if execute() is not called
    //bool isExecuted = false;
public:
	SwapCommand(IntVector& v, size_t from, size_t to);

	virtual void execute() override;
	virtual void undo() override;
};