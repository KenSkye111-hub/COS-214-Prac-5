#ifndef CAMPUS_GUARD_FACADE_H
#define CAMPUS_GUARD_FACADE_H

class CommunicationSystem;
class AccessControlSystem;
class SecuritySystem;
class MedicalSystem;
class CommandDispatcher;
class Incident;

class CampusGuardFacade {
private:
    CommunicationSystem* comms;
    AccessControlSystem* access;
    SecuritySystem* security;
    MedicalSystem* medical;
    CommandDispatcher* dispatcher;

public:
    CampusGuardFacade(
        CommunicationSystem* comms,
        AccessControlSystem* access,
        SecuritySystem* security,
        MedicalSystem* medical,
        CommandDispatcher* dispatcher
    );

    void handleMedicalEmergency(Incident* incident);
    void handleSecurityEmergency(Incident* incident);
    void handleNaturalDisaster(Incident* incident);
};

#endif