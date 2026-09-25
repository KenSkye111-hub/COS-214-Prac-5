#ifndef STATE_H
#define STATE_H

#include <string>

class Incident;

//state
class OperationalState{
  public:
    virtual void changeState(Incident* i, std::string event) =0;
    virtual ~OperationalState();
};

//concrete states
class DispatchedState: public OperationalState{
  public:
    void changeState(Incident* i, std::string event) override;
};
class InProgressState: public OperationalState{
  public:
   void changeState(Incident* i, std::string event) override;
};
class FinishedState: public OperationalState{
  public:
   void changeState(Incident* i, std::string event) override;
};
#endif