#include "CampusGuardFacade.h"

#include "Coordinator.h"
#include "CommandDispatcher.h"
#include "Command.h"
#include "Incident.h"
#include "System.h"

#include <vector>

CampusGuardFacade::CampusGuardFacade(
    CommunicationSystem* comms,
    AccessControlSystem* access,
    SecuritySystem* security,
    MedicalSystem* medical,
    CommandDispatcher* dispatcher
)
    : comms(comms),
      access(access),
      security(security),
      medical(medical),
      dispatcher(dispatcher) {
}

CampusGuardFacade::~CampusGuardFacade(){
  for(Coordinator* c: coordinators) delete c;
}

void CampusGuardFacade::handleMedicalEmergency(Incident* incident) {
    Coordinator* cc = new MedicalIncidentCoordinator(comms, access, security, medical);
    coordinators.push_back(cc);

    comms->setCoordinator(cc);
    access->setCoordinator(cc);
    security->setCoordinator(cc);
    medical->setCoordinator(cc);

    std::vector<Command*> commands =
        cc->handleIncident(incident, "Medical Emergency");

    for (Command* command : commands) {
        dispatcher->executeCommand(command);
    }
}

void CampusGuardFacade::handleSecurityEmergency(Incident* incident) {
    Coordinator* cc = new SecurityIncidentCoordinator(comms, access, security, medical);
    coordinators.push_back(cc);

    comms->setCoordinator(cc);
    access->setCoordinator(cc);
    security->setCoordinator(cc);
    medical->setCoordinator(cc);

    std::vector<Command*> commands =
        cc->handleIncident(incident, "Security Emergency");

    for (Command* command : commands) {
        dispatcher->executeCommand(command);
    }
}

void CampusGuardFacade::handleNaturalDisaster(Incident* incident) {
    Coordinator* cc = new NaturalDisasterCoordinator(comms, access, security, medical);
    coordinators.push_back(cc);

    comms->setCoordinator(cc);
    access->setCoordinator(cc);
    security->setCoordinator(cc);
    medical->setCoordinator(cc);

    std::vector<Command*> commands =
        cc->handleIncident(incident, "Natural Disaster");

    for (Command* command : commands) {
        dispatcher->executeCommand(command);
    }
}

void CampusGuardFacade::undoLastAction() {
  dispatcher->undoLast();
}