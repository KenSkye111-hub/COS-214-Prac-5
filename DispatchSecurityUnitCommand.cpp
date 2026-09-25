#include "DispatchSecurityUnitCommand.h"
#include "System.h"

DispatchSecurityUnitCommand::DispatchSecurityUnitCommand(SecuritySystem* r) : receiver(r) { }

void DispatchSecurityUnitCommand::execute() { receiver->dispatchUnit(); }

void DispatchSecurityUnitCommand::undo() {
  // TODO: same gap as DispatchUnitCommand::undo() - add a recall method when you need it.
}
