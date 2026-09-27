#include "EvacuateAreaCommand.h"

EvacuateAreaCommand::EvacuateAreaCommand(Area* receiver){
    this->receiver = receiver;
}

void EvacuateAreaCommand::execute(){
    receiver->setStatus(AreaStatus::RESTRICTED);
}

void EvacuateAreaCommand::undo(){
    receiver->setStatus(AreaStatus::UNLOCKED);
}