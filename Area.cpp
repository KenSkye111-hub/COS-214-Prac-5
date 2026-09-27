#include <iostream>
#include "Area.h"

Area::Area(AreaStatus s) : status(s) {}

AreaStatus Area::getStatus() const {
    return status;
}

void Area::setStatus(AreaStatus s) {
    status = s;
}