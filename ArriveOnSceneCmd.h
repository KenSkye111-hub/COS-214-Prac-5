#ifndef ARRIVEONSCENECMD_H
#define ARRIVEONSCENECMD_H

#include "Command.h"

class MedicalSystem;

class ArriveOnSceneCommand: public Command {
  private:
    MedicalSystem* receiver;

  public:
    ArriveOnSceneCommand(MedicalSystem* r);
    void execute() override;
    void undo() override;
};

#endif