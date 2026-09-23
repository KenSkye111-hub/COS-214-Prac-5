#include <iostream>
#include "Area.h"

Area::Area(const std::string& id){
    this->id = id;
    this->state = AreaState::UNLOCKED;
}

std::string Area::getId() const{
    return id;
}

AreaState Area::getState() const{
    return state;
}

//caller(command) becomes responsible for eventually deleting it.
AreaMemento* Area::createMemento() const{
    return new AreaMemento(state);
}

//restore back to the state it was in when the memento was created. If the memento is nullptr, then ignore it and print a message to std::cout.
void Area::restore(AreaMemento* memento){
    if(memento == nullptr){
        std::cout << "[Area " << id << "] restore() called with no memento — ignoring\n";
        return;
    }
    this->state = memento->getState();
    std::cout << "[Area " << id << "] restored\n";
}

void Area::lock(){
    this->state = AreaState::LOCKED;
    std::cout << "[Area " << id << "] locked\n";
}
 
void Area::unlock(){
    this->state = AreaState::UNLOCKED;
    std::cout << "[Area " << id << "] unlocked\n";
}
 
void Area::restrict(){
    this->state = AreaState::RESTRICTED;
    std::cout << "[Area " << id << "] restricted\n";
}