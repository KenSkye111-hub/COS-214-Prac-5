#ifndef SYSTEM_H
#define SYSTEM_H

#include "string"
#include "vector"
#include "map"

#include "Communication.h"
#include "AreaMemento.h"

class Coordinator;

//Colleague

class System {
  private:
    Coordinator* coordinator;
  protected: 
    void reportEvent(std::string event); //notify coordinator& keep between subclasses
  public:
    virtual ~System(); //virtual desctructor since polymorphic base
    void setCoordinator(Coordinator* c);
    
};

//Concrete Colleagues

class CommunicationSystem : public System { //also plays role in Adapter pattern
  private:
    alertSender* sender;
  public:
    CommunicationSystem(alertSender* s);
    void sendAlert(std::string recipients, std::string message);
};

class AccessControlSystem : public System {
  private:
    std::map<std::string, Area> areas;

  public:
    void addArea(std::string areaId, Area a);

    AreaMemento lockArea(std::string areaId);
    AreaMemento unlockArea(std::string areaId);
    AreaMemento restrictArea(std::string areaId);
    void restoreArea(std::string areaId, AreaMemento m);
};

class SecuritySystem : public System {
  public:
    void dispatchUnit();
};

class MedicalSystem : public System {
  public:
    void dispatchUnit();
    //logic for internal state changes on incident
    void arriveOnScene(); 
    void completeAllTreatment();
};

#endif
