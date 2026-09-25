#ifndef DISPATCH_SECURITY_UNIT_COMMAND_H
#define DISPATCH_SECURITY_UNIT_COMMAND_H

#include "Command.h"

class SecuritySystem;

// Mirrors DispatchUnitCommand but typed to SecuritySystem - SecuritySystem already
// had dispatchUnit() on it, but nothing in the Command layer could call it yet.
class DispatchSecurityUnitCommand : public Command {
  private:
    SecuritySystem* receiver;

  public:
    DispatchSecurityUnitCommand(SecuritySystem* r);
    void execute() override;
    void undo() override;
};

#endif
