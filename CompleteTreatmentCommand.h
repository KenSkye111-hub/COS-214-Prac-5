#ifndef COMPLETETREATMENTCOMMAND_H
#define COMPLETETREATMENTCOMMAND_H

#include "Command.h"

class MedicalSystem;

class CompleteTreatmentCommand : public Command {
  private:
    MedicalSystem* receiver;

  public:
    CompleteTreatmentCommand(MedicalSystem* r);
    void execute() override;
    void undo() override;
};

#endif