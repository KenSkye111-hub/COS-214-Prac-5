#ifndef UNLOCKAREACOMMAND_H
#define UNLOCKAREACOMMAND_H
//Concrete Command
//unlock guven area. undo() reverses this by locking it again

#include <string>

#include "Command.h"
#include "AreaMemento.h"

class AccessControlSystem;

class UnlockAreaCommand : public Command {
  private:
    AccessControlSystem* receiver;
    std::string areaId;
    AreaMemento* savedState;

  public:
    UnlockAreaCommand(AccessControlSystem* r, std::string areaId);
    ~UnlockAreaCommand();
    void execute() override;
    void undo() override;
};

#endif //UNLOCKAREACOMMAND_H