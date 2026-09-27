#ifndef DISPATCHUNITCOMMAND_H
#define DISPATCHUNITCOMMAND_H

#include "Command.h"
#include "System.h"


class DispatchUnitCommand: public Command {
public:
    DispatchUnitCommand(System* receiver);
    void execute() override;
    void undo() override;

private:
    System* receiver;
};

#endif 