#include "SwapCommand.h"

SwapCommand::SwapCommand(IntVector& v, size_t from, size_t to)
	: VectorCommand(v), from(from), to(to) { }

void SwapCommand::execute() {
	std::swap(v[from], v[to]);
}

void SwapCommand::undo() {
	std::swap(v[to], v[from]);
}