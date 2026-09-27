#include "DispatchMedicalCmd.h"
#include "System.h"

DispatchMedicalUnitCommand::DispatchMedicalUnitCommand(MedicalSystem* r) : receiver(r) { }

void DispatchMedicalUnitCommand::execute() { receiver->dispatchUnit(); }

void DispatchMedicalUnitCommand::undo() {
}
