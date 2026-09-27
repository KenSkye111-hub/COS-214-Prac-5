#include <iostream>
#include "DispatchUnitCommand.h"

DispatchUnitCommand::DispatchUnitCommand(System* receiver) {
    this->receiver = receiver;
}

void DispatchUnitCommand::execute() {
    receiver->dispatchUnit();
}

void DispatchUnitCommand::undo() {
    std::cout << "[DispatchUnitCommand] Dispatch cannot be undone — unit already en route\n";
}