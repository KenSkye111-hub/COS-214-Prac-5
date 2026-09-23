#ifndef AREAMEMENTO_H
#define AREAMEMENTO_H
//MEMENTO

//possible states of an area
enum class AreaState{
    UNLOCKED,
    LOCKED,
    RESTRICTED
};


class AreaMemento{
    private:
        AreaState state;
    
    public:
        AreaMemento(AreaState state);
        AreaState getState() const;
};

#endif //AREAMEMENTO_H