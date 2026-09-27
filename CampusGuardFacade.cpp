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

void CampusGuardFacade::handleMedicalEmergency(Incident* incident) {
    MedicalIncidentCoordinator coordinator(
        comms, access, security, medical
    );

    comms->setCoordinator(&coordinator);
    access->setCoordinator(&coordinator);
    security->setCoordinator(&coordinator);
    medical->setCoordinator(&coordinator);

    std::vector<Command*> commands =
        coordinator.handleIncident(incident, "Medical Emergency");

    for (Command* command : commands) {
        dispatcher->executeCommand(command);
    }
}

void CampusGuardFacade::handleSecurityEmergency(Incident* incident) {
    SecurityIncidentCoordinator coordinator(
        comms, access, security, medical
    );

    comms->setCoordinator(&coordinator);
    access->setCoordinator(&coordinator);
    security->setCoordinator(&coordinator);
    medical->setCoordinator(&coordinator);

    std::vector<Command*> commands =
        coordinator.handleIncident(incident, "Security Emergency");

    for (Command* command : commands) {
        dispatcher->executeCommand(command);
    }
}

void CampusGuardFacade::handleNaturalDisaster(Incident* incident) {
    NaturalDisasterCoordinator coordinator(
        comms, access, security, medical
    );

    comms->setCoordinator(&coordinator);
    access->setCoordinator(&coordinator);
    security->setCoordinator(&coordinator);
    medical->setCoordinator(&coordinator);

    std::vector<Command*> commands =
        coordinator.handleIncident(incident, "Natural Disaster");

    for (Command* command : commands) {
        dispatcher->executeCommand(command);
    }
}