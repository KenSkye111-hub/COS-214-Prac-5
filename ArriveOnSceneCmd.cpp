#include <iostream>
#include "ArriveOnSceneCmd.h"
#include "System.h"

ArriveOnSceneCommand::ArriveOnSceneCommand(MedicalSystem* r) : receiver(r) { }

void ArriveOnSceneCommand::execute() {
  receiver->arriveOnScene();
}

void ArriveOnSceneCommand::undo() {
  std::cout << "[ArriveOnSceneCommand] Cannot undo — unit has already arrived\n";
}