#ifndef UNLOCKAREACOMMAND_H
#define UNLOCKAREACOMMAND_H
//Concrete Command
//unlock guven area. undo() reverses this by locking it again

#include "Command.h"
#include "Area.h"

class UnlockAreaCommand: public Command{
    private:
        Area* receiver;

    public:
        UnlockAreaCommand(Area* receiver);
        void execute() override;
        void undo() override;
};

#endif //UNLOCKAREACOMMAND_H