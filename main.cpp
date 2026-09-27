#include <iostream>

#include "Communication.h"
#include "System.h"
#include "Incident.h"
#include "CommandDispatcher.h"
#include "CampusGuardFacade.h"

int main(){

//1. build systems that form the heart of incident handling
//1.1. build adapter chain for communicating alerts
  legacyEmailService legacy; 
  smsService sms(&legacy);
  CommunicationSystem comms(&sms);

//1.2. create our "campus", a.k.a: set up areas for access control system 
  AccessControlSystem access;
  access.addArea("PinkZone", Area());
  access.addArea("BlueZone", Area());
  access.addArea("GreenZone", Area());
  access.addArea("YellowZone", Area());

//1.3. create security system and medical system
  SecuritySystem security;
  MedicalSystem medical;

//2. create the command dispatcher
  CommandDispatcher dispatcher;

//3. create Facade that coordinates everything, even coordinates coordinator ;)
  CampusGuardFacade facade(&comms, &access, &security, &medical, &dispatcher);

//4. create incidents that should be handled by entire "system"
//4.1. create & handle medical incident
std::cout << "Medical incident reported in PinkZone!\n";
Incident i1("PinkZone");

facade.handleMedicalEmergency(&i1);

medical.arriveOnScene();
medical.completeAllTreatment();

std::cout << "Security Theft reported in GreenZone!\n";
Incident i2("GreenZone");

facade.handleSecurityEmergency(&i2);

std::cout << "Fire reported in YellowZone!\n";
Incident i3("YellowZone");

facade.handleNaturalDisaster(&i3);

std::cout << "Undoing last action\n";
facade.undoLastAction();

return 0;
}