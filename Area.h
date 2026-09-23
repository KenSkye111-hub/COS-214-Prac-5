#ifndef AREA_H
#define AREA_H
//Originator and Receiver

#include <string>
#include "AreaMemento.h"

class Area{
    private:
        std::string id;
        AreaState state;

    public:
        Area(const std::string& id);
        std::string getId() const;
        AreaState getState() const;
        AreaMemento* createMemento() const;
        void restore(AreaMemento* memento);
        void lock();
        void unlock();
        void restrict();
};


#endif //AREA_H