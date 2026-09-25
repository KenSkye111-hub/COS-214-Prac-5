#ifndef COORDINATOR_H
#define COORDINATOR_H

#include <string>
#include <vector>

class CommunicationSystem;
class AccessControlSystem;
class SecuritySystem;
class MedicalSystem;
class System;
class Incident;
class Command;

//mediator
class Coordinator{
  protected:
    CommunicationSystem* comms;
    AccessControlSystem* access;
    SecuritySystem* security;
    MedicalSystem* medical;
    Incident* incident;

    virtual std::vector<Command*> coordinateResponse(Incident* i) =0;
  public:
    virtual ~Coordinator(); //virtual desctructor since polymorphic base
    Coordinator(CommunicationSystem*, AccessControlSystem*, SecuritySystem*, MedicalSystem*);
    
    std::vector<Command*> handleIncident(Incident* i, std::string type); // template method
    void notify(System* system, std::string event);
};

//concrete mediator
class MedicalIncidentCoordinator: public Coordinator{
  public:
    using Coordinator::Coordinator;
    std::vector<Command*> coordinateResponse(Incident* i) override;
};

class SecurityIncidentCoordinator: public Coordinator{
  public:
    using Coordinator::Coordinator;
    std::vector<Command*> coordinateResponse(Incident* i) override;
};

class NaturalDisasterCoordinator: public Coordinator{
  public:
    using Coordinator::Coordinator;
    std::vector<Command*> coordinateResponse(Incident* i) override;
};


#endif