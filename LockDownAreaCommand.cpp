#include "LockDownAreaCommand.h"
#include "System.h"

LockDownAreaCommand::LockDownAreaCommand(AccessControlSystem* r, std::string areaId)
  : receiver(r), areaId(areaId), savedState(nullptr) { }

LockDownAreaCommand::~LockDownAreaCommand() { delete savedState; }

void LockDownAreaCommand::execute() {
  AreaMemento saved = receiver->lockArea(areaId);
  savedState = new AreaMemento(saved);
}

void LockDownAreaCommand::undo() {
  if (savedState) receiver->restoreArea(areaId, *savedState);
}
