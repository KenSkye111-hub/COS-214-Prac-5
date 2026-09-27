#include "State.h"
#include "Incident.h"
#include "Event.h"
#include <iostream>

OperationalState::~OperationalState() { }

void DispatchedState::changeState(Incident* i, std::string event) {
    if (event == Event::ARRIVED) {
        std::cout << "[STATE] Incident: Dispatched -> In Progress\n";
        i->setState(new InProgressState());
    }
    else {
        std::cout << "[STATE] Invalid event '" << event
                  << "' while incident is Dispatched.\n";
    }
}

void InProgressState::changeState(Incident* i, std::string event) {
    if (event == Event::COMPLETE) {
        std::cout << "[STATE] Incident: In Progress -> Finished\n";
        i->setState(new FinishedState());
    }
    else {
        std::cout << "[STATE] Invalid event '" << event
                  << "' while incident is In Progress.\n";
    }
}

void FinishedState::changeState(Incident*, std::string event) {
    std::cout << "[STATE] Incident is already Finished. "
              << "Event '" << event << "' cannot be performed.\n";
}