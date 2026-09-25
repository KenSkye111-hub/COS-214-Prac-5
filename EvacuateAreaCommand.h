#ifndef EVACUATEAREACOMMAND_H
#define EVACUATEAREACOMMAND_H
//Concrete Command
//evacutes given area

#include <string>

#include "Command.h"
#include "AreaMemento.h"

class AccessControlSystem;

class EvacuateAreaCommand : public Command {
  private:
    AccessControlSystem* receiver;
    std::string areaId;
    AreaMemento* savedState;

  public:
    EvacuateAreaCommand(AccessControlSystem* r, std::string areaId);
    ~EvacuateAreaCommand();
    void execute() override;
    void undo() override;
};

#endif //EVACUATEAREACOMMAND_H