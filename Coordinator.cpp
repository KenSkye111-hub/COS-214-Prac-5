#include "Coordinator.h"

#include "System.h"
#include "Incident.h"
#include "State.h"
#include "DispatchMedicalCmd.h"
#include "DispatchSecurityCmd.h"
#include "LockDownAreaCommand.h"
#include "UnlockAreaCommand.h"
#include "EvacuateAreaCommand.h"

Coordinator::~Coordinator(){ }

Coordinator::Coordinator(CommunicationSystem* cs, AccessControlSystem* acs, SecuritySystem* ss, MedicalSystem* ms) 
  : comms(cs), access(acs), security(ss), medical(ms), incident(nullptr) { }

//template method
std::vector<Command*> Coordinator::handleIncident(Incident* i, std::string type){ 
  incident = i;
  comms->sendAlert("all", "New Incident Reported: " + type); //common step
  std::vector<Command*> cmds = coordinateResponse(i); // will vary by type
  i->setState(new DispatchedState()); //common step
  return cmds;
}

void Coordinator::notify(System* system, std::string event){ 
  incident->changeStatus(event); 
}

std::vector<Command*> MedicalIncidentCoordinator::coordinateResponse(Incident* i){
  std::vector<Command*> cmds;
  cmds.push_back(new DispatchMedicalUnitCommand(medical));
  cmds.push_back(new UnlockAreaCommand(access, i->getAreaId()));  // clear a path for the medical unit
  return cmds;
}

std::vector<Command*> SecurityIncidentCoordinator::coordinateResponse(Incident* i){
  std::vector<Command*> cmds;
  cmds.push_back(new LockDownAreaCommand(access, i->getAreaId()));
  cmds.push_back(new DispatchSecurityUnitCommand(security));
  return cmds;
}

std::vector<Command*> NaturalDisasterCoordinator::coordinateResponse(Incident* i){
   std::vector<Command*> cmds;
  cmds.push_back(new LockDownAreaCommand(access, i->getAreaId()));
  cmds.push_back(new DispatchMedicalUnitCommand(medical));
  cmds.push_back(new EvacuateAreaCommand(access, i->getAreaId()));
  return cmds;
}