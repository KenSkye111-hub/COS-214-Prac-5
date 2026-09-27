#ifndef DISPATCH_SECURITY_CMD_H
#define DISPATCH_SECURITY_CMD_H

#include "Command.h"

class SecuritySystem;

class DispatchSecurityUnitCommand : public Command {
  private:
    SecuritySystem* receiver;

  public:
    DispatchSecurityUnitCommand(SecuritySystem* r);
    void execute() override;
    void undo() override;
};

#endif
