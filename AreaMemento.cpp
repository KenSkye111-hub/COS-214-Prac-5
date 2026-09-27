#include "AreaMemento.h"

AreaMemento::AreaMemento(AreaStatus s) : savedStatus(s) {}

AreaStatus AreaMemento::getStatus() const {
    return savedStatus;
}
 