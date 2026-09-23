#ifndef COMMANDDISPATCHER_H
#define COMMANDDISPATCHER_H
//Invoker

#include <vector>
#include "Command.h"

class CommandDispatcher{
    private:
        std::vector<Command*> history;

    public:
        ~CommandDispatcher();
        void executeCommand(Command* command);
        void undoLast();
    
};


#endif //COMMANDDISPATCHER_H