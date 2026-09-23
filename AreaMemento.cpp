#include "AreaMemento.h"

//store snapshot passed in by Area at the moment of creation.
AreaMemento::AreaMemento(AreaState state): state(state){
}
 
//snapshot back so Area::restore() can read the saved state.
AreaState AreaMemento::getState() const{
    return state;
}
 