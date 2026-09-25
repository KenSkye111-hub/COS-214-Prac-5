#ifndef DISPATCH_UNIT_COMMAND_H
#define DISPATCH_UNIT_COMMAND_H

#include "Command.h"

class MedicalSystem;

class DispatchUnitCommand : public Command {
  private:
    MedicalSystem* receiver;

  public:
    DispatchUnitCommand(MedicalSystem* r);
    void execute() override;
    void undo() override;
};

#endif
