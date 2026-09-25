#include "EvacuateAreaCommand.h"
#include "System.h"

EvacuateAreaCommand::EvacuateAreaCommand(AccessControlSystem* r, std::string areaId)
  : receiver(r), areaId(areaId), savedState(nullptr) { }

EvacuateAreaCommand::~EvacuateAreaCommand() { delete savedState; }

void EvacuateAreaCommand::execute() {
  AreaMemento saved = receiver->restrictArea(areaId);
  savedState = new AreaMemento(saved);
}

void EvacuateAreaCommand::undo() {
  if (savedState) receiver->restoreArea(areaId, *savedState);
}