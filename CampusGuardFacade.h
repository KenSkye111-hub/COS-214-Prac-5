#ifndef CAMPUS_GUARD_FACADE_H
#define CAMPUS_GUARD_FACADE_H

#include <vector>

class CommunicationSystem;
class AccessControlSystem;
class SecuritySystem;
class MedicalSystem;
class CommandDispatcher;
class Incident;
class Coordinator;

class CampusGuardFacade {
private:
    CommunicationSystem* comms;
    AccessControlSystem* access;
    SecuritySystem* security;
    MedicalSystem* medical;
    CommandDispatcher* dispatcher;

    //Facade will own all heap-based coordinators
    //better memory control & management
    std::vector<Coordinator*> coordinators;

public:
    CampusGuardFacade(
        CommunicationSystem* comms,
        AccessControlSystem* access,
        SecuritySystem* security,
        MedicalSystem* medical,
        CommandDispatcher* dispatcher
    );
    ~CampusGuardFacade();

    void handleMedicalEmergency(Incident* incident);
    void handleSecurityEmergency(Incident* incident);
    void handleNaturalDisaster(Incident* incident);

    void undoLastAction();
};

#endif