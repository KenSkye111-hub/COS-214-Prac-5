#include <iostream>
#include "CommandDispatcher.h"

//clean up anything still in history not deleted
CommandDispatcher::~CommandDispatcher(){
    while(!history.empty()){
        delete history.back();
        history.pop_back();
    }
}

//execute a command and add it to the history
void CommandDispatcher::executeCommand(Command* command){
    command->execute();
    history.push_back(command);
}

//undo the last command and remove it from the history
void CommandDispatcher::undoLast(){
    if(history.empty()){
        std::cout << "[CommandDispatcher] Nothing to undo \n";
        return;
    }

    Command* last = history.back();
    history.pop_back();

    last->undo();
    delete last;
}