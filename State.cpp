#include "State.h"
#include "Incident.h"

OperationalState::~OperationalState(){ }

void DispatchedState::changeState(Incident* i, std::string event){
  if(event == "arrived") i->setState(new InProgressState());
}

void InProgressState::changeState(Incident* i, std::string event){
  if(event == "complete") i->setState(new FinishedState());
}

void FinishedState::changeState(Incident* i, std::string event){ 
  //do nothing once finished
}