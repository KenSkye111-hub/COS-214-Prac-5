#ifndef AREAMEMENTO_H
#define AREAMEMENTO_H
//MEMENTO

#include "Area.h"

class AreaMemento{
    private:
        AreaStatus savedStatus;
    
    public:
        AreaMemento(AreaStatus s = AreaStatus::UNLOCKED);
        AreaStatus getStatus() const;
};

#endif //AREAMEMENTO_H