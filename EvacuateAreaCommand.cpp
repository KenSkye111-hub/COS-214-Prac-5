#include "EvacuateAreaCommand.h"

EvacuateAreaCommand::EvacuateAreaCommand(Area* receiver){
    this->receiver = receiver;
}

void EvacuateAreaCommand::execute(){
    receiver->restrict();
}

void EvacuateAreaCommand::undo(){
    receiver->unlock();
}