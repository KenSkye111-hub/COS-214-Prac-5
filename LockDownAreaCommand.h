#ifndef LOCKDOWNAREACOMMAND_H
#define LOCKDOWNAREACOMMAND_H

#include <string>
#include "Command.h"
#include "System.h"       // AccessControlSystem is teammate's real class
#include "AreaMemento.h"


class LockDownAreaCommand: public Command{
public:
    LockDownAreaCommand(AccessControlSystem* receiver, const std::string& areaId);
    void execute() override;
    void undo() override;

private:
    AccessControlSystem* receiver;
    std::string areaId;
    AreaMemento savedState; 
    bool hasExecuted;
};

#endif 