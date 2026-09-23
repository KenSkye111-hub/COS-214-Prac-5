#include "UnlockAreaCommand.hh"

UnlockAreaCommand::UnlockAreaCommand(Area* receiver){
    this->receiver = receiver;
}

void UnlockAreaCommand::execute(){
    receiver->unlock();
}

void UnlockAreaCommand::undo(){
    receiver->lock();
}