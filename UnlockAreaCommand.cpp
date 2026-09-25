#include "UnlockAreaCommand.h"
#include "System.h"

UnlockAreaCommand::UnlockAreaCommand(AccessControlSystem* r, std::string areaId)
  : receiver(r), areaId(areaId), savedState(nullptr) { }

UnlockAreaCommand::~UnlockAreaCommand() { delete savedState; }

void UnlockAreaCommand::execute() {
  AreaMemento saved = receiver->unlockArea(areaId);
  savedState = new AreaMemento(saved);
}

void UnlockAreaCommand::undo() {
  if (savedState) receiver->restoreArea(areaId, *savedState);
}