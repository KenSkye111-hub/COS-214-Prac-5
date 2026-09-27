#ifndef EVACUATEAREACOMMAND_H
#define EVACUATEAREACOMMAND_H
//Concrete Command
//evacutes given area

#include "Command.h"
#include "Area.h"

class EvacuateAreaCommand: public Command{
    private:
        Area* receiver;

    public:
        EvacuateAreaCommand(Area* receiver);
        void execute() override;
        void undo() override;
};

#endif //EVACUATEAREACOMMAND_H