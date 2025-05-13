#include "SortCommand.h"

SortCommand::SortCommand(IntVector& v) : VectorCommand(v) {}

void SortCommand::sortVector(IntVector& v) {
    for (size_t i = 0; i < v.getSize() - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < v.getSize(); j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(v[i], v[minIndex]);
        }
    }
}

void SortCommand::execute() {
    if (snapshot) {
        delete snapshot;
    }
    snapshot = new IntVector(v);
    sortVector(v);
}

void SortCommand::undo() {
    if (snapshot) {
        v = std::move(*snapshot);
        delete snapshot;
        snapshot = nullptr;
    }
}