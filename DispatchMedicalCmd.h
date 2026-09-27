#ifndef DISPATCH_MEDICAL_CMD_H
#define DISPATCH_MEDICAL_CMD_H

#include "Command.h"

class MedicalSystem;

class DispatchMedicalUnitCommand : public Command {
  private:
    MedicalSystem* receiver;

  public:
    DispatchMedicalUnitCommand(MedicalSystem* r);
    void execute() override;
    void undo() override;
};

#endif
