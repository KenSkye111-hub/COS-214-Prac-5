#include <iostream>
#include "CompleteTreatmentCommand.h"
#include "System.h"

CompleteTreatmentCommand::CompleteTreatmentCommand(MedicalSystem* r) : receiver(r) { }

void CompleteTreatmentCommand::execute() {
  receiver->completeAllTreatment();
}

void CompleteTreatmentCommand::undo() {
  std::cout << "[CompleteTreatmentCommand] Cannot undo — treatment already completed\n";
}