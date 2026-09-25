#ifndef LOCK_DOWN_AREA_COMMAND_H
#define LOCK_DOWN_AREA_COMMAND_H

#include <string>

#include "Command.h"
#include "AreaMemento.h"

class AccessControlSystem;

class LockDownAreaCommand : public Command {
  private:
    AccessControlSystem* receiver;
    std::string areaId;
    AreaMemento* savedState;

  public:
    LockDownAreaCommand(AccessControlSystem* r, std::string areaId);
    ~LockDownAreaCommand();
    void execute() override;
    void undo() override;
};

#endif
