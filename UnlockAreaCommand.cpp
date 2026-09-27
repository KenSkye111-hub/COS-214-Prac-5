#include "UnlockAreaCommand.h"

UnlockAreaCommand::UnlockAreaCommand(Area* receiver){
    this->receiver = receiver;
}

void UnlockAreaCommand::execute(){
    receiver->setStatus(AreaStatus::UNLOCKED);
}

void UnlockAreaCommand::undo(){
    receiver->setStatus(AreaStatus::LOCKED);
}