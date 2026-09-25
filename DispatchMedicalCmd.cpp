#include "DispatchUnitCommand.h"
#include "System.h"

DispatchUnitCommand::DispatchUnitCommand(MedicalSystem* r) : receiver(r) { }

void DispatchUnitCommand::execute() { receiver->dispatchUnit(); }

void DispatchUnitCommand::undo() {
  // TODO: MedicalSystem doesn't have a recallUnit() yet - add one there and call
  // it here once "undo a dispatch" is actually defined for your team.
}
