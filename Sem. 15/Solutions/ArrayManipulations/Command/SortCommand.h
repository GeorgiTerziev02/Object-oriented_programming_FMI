#pragma once
#include "VectorCommand.h"
#include "IntVector.h"

class SortCommand : public VectorCommand {
	const IntVector* snapshot = nullptr;

	static void sortVector(IntVector& v);
public:
	SortCommand(IntVector& v);

	void execute() override;
	void undo() override;
};