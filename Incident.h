#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class OperationalState;

class Incident{
  private:
    OperationalState* state;
    std::string areaId;
  public:
    Incident(std::string areaId);
    ~Incident();
    std::string getAreaId();
    void setState(OperationalState* s);
    void changeStatus(std::string event);

};

#endif