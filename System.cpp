#include "System.h"
#include "Coordinator.h"
#include "Event.h"
#include <iostream>

System::~System() { }

void System::setCoordinator(Coordinator* c) { coordinator = c; }

void System::reportEvent(std::string event){
  std::cout << "System reporting: " << event << " to coordinator\n";
  if(coordinator) coordinator->notify(this, event);
}

CommunicationSystem::CommunicationSystem(alertSender* s) : sender(s){ }

void CommunicationSystem::sendAlert(std::string recipients, std::string message){
  std::cout << "CommunicationSystem sending alert to: " << recipients << std::endl;

  sender->sendAlert(recipients, message);
}

void SecuritySystem::dispatchUnit(){ 
  std::cout << "[DISPATCHING UNIT] - security system\n";
}

void MedicalSystem::dispatchUnit(){ 
  std::cout << "[DISPATCHING UNIT] - medical system\n";
}

void MedicalSystem::arriveOnScene(){
  std::cout << "[ARRIVING ON SCENE] - medical unit\n";
  reportEvent(Event::ARRIVED);
}

void MedicalSystem::completeAllTreatment(){
  std::cout << "[Leaving scene, everyone ok] - medical unit\n";
  reportEvent(Event::COMPLETE);
}

void AccessControlSystem::addArea(std::string areaId, Area a) {
  std::cout << "AccessControlSystem registering area: " << areaId << std::endl; 
  areas[areaId] = a;
}

AreaMemento AccessControlSystem::lockArea(std::string areaId) {
  std::cout << "AccessControlSystem locking area: " << areaId << std::endl; 
  AreaMemento saved(areas[areaId].getStatus());
  areas[areaId].setStatus(AreaStatus::LOCKED);
  return saved;
}

AreaMemento AccessControlSystem::unlockArea(std::string areaId) {
  std::cout << "AccessControlSystem unlocking area: " << areaId << std::endl; 
  AreaMemento saved(areas[areaId].getStatus());
  areas[areaId].setStatus(AreaStatus::UNLOCKED);
  return saved;
}

AreaMemento AccessControlSystem::restrictArea(std::string areaId) {
  std::cout << "AccessControlSystem restricting area: " << areaId << std::endl; 
  AreaMemento saved(areas[areaId].getStatus());
  areas[areaId].setStatus(AreaStatus::RESTRICTED);
  return saved;
}

void AccessControlSystem::restoreArea(std::string areaId, AreaMemento m) {
  std::cout << "AccessControlSystem restoring area: " << areaId << std::endl; 
  areas[areaId].setStatus(m.getStatus());
}