#ifndef AREAMEMENTO_H
#define AREAMEMENTO_H

#include "Area.h"

class AreaMemento {
  private:
    AreaStatus savedStatus;

  public:
    AreaMemento(AreaStatus s = AreaStatus::UNLOCKED);
    AreaStatus getStatus() const;
};

#endif