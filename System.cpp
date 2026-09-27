#include "System.h"
#include <iostream>

System::~System() { }

void System::setCoordinator(Coordinator* c) { coordinator = c; }

CommunicationSystem::CommunicationSystem(alertSender* s) : sender(s){ }

void CommunicationSystem::sendAlert(std::string recipients, std::string message){
  sender->sendAlert(recipients, message);
}

void SecuritySystem::dispatchUnit(){ 
  std::cout << "[DISPATCHING UNIT] - security system\n";
}

void MedicalSystem::dispatchUnit(){ 
  std::cout << "[DISPATCHING UNIT] - medical system\n";
}

void AccessControlSystem::addArea(std::string areaId, Area a) {
  areas[areaId] = a;
}

AreaMemento AccessControlSystem::lockArea(std::string areaId) {
  AreaMemento saved(areas[areaId].getStatus());
  areas[areaId].setStatus(AreaStatus::LOCKED);
  return saved;
}

AreaMemento AccessControlSystem::unlockArea(std::string areaId) {
  AreaMemento saved(areas[areaId].getStatus());
  areas[areaId].setStatus(AreaStatus::UNLOCKED);
  return saved;
}

AreaMemento AccessControlSystem::restrictArea(std::string areaId) {
  AreaMemento saved(areas[areaId].getStatus());
  areas[areaId].setStatus(AreaStatus::RESTRICTED);
  return saved;
}

void AccessControlSystem::restoreArea(std::string areaId, AreaMemento m) {
  areas[areaId].setStatus(m.getStatus());
}