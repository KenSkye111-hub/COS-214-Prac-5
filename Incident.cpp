#include "Incident.h"
#include "State.h"

Incident::Incident(std::string areaId) : state(new DispatchedState()), areaId(areaId) { }

Incident::~Incident(){ delete state; }

std::string Incident::getAreaId(){ return areaId; }

void Incident::setState(OperationalState* s){
  delete state; // free the old state for overwrite
  state = s;
}

void Incident::changeStatus(std::string event){ state->changeState(this, event); }