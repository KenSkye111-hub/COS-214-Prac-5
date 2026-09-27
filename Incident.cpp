#include "Incident.h"
#include "State.h"

#include <iostream>

Incident::Incident(std::string areaId) : state(new DispatchedState()), areaId(areaId) {
  std::cout << "Incident [" << areaId << "], State [ " << state->getName() << "]\n";
 }

Incident::~Incident(){ delete state; }

std::string Incident::getAreaId(){ return areaId; }

void Incident::setState(OperationalState* s){
  std::cout << "Incident [" << areaId << "], State [" << (state ? state->getName() : "None" ) << "->" << s->getName() << "]\n";

  delete state; // free the old state for overwrite
  state = s;
}

void Incident::changeStatus(std::string event){ 
  std::cout << "Incident [" << areaId << "] received event " << event << ", State [" << state->getName() << "]\n";
  state->changeState(this, event); 
}