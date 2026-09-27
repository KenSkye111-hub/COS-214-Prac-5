#include "DispatchSecurityCmd.h"
#include "System.h"

DispatchSecurityUnitCommand::DispatchSecurityUnitCommand(SecuritySystem* r) : receiver(r) { }

void DispatchSecurityUnitCommand::execute() { receiver->dispatchUnit(); }

void DispatchSecurityUnitCommand::undo() {
}
