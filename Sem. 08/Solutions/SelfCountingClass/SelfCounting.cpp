#include "SelfCounting.h"

size_t SelfCounting::livingInstances = 0;
size_t SelfCounting::createdInstances = 0;

size_t SelfCounting::getLivingInstances() {
    return livingInstances;
}

size_t SelfCounting::getCreatedInstances() {
    return createdInstances;
}

SelfCounting::SelfCounting() : localTempVariable(5) {
    createdInstances++;
    livingInstances++;
}

SelfCounting::SelfCounting(const SelfCounting& other) : localTempVariable(other.localTempVariable) {
    createdInstances++;
    livingInstances++;
}

SelfCounting::~SelfCounting() {
    livingInstances--;
}