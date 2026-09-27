#include "LockDownAreaCommand.h"
#include <iostream>

LockDownAreaCommand::LockDownAreaCommand(AccessControlSystem* receiver, const std::string& areaId)
    : savedState(AreaStatus::UNLOCKED) {
    this->receiver = receiver;
    this->areaId = areaId;
    this->hasExecuted = false;
}

void LockDownAreaCommand::execute() {
    savedState = receiver->lockArea(areaId);
    hasExecuted = true;
}

void LockDownAreaCommand::undo() {
    if (!hasExecuted) {
        std::cout << "[LockDownAreaCommand] Nothing to undo for area " << areaId << "\n";
        return;
    }
    receiver->restoreArea(areaId, savedState);
    hasExecuted = false;
}