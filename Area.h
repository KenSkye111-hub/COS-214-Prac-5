#ifndef AREA_H
#define AREA_H
//Originator and Receiver

enum class AreaStatus { UNLOCKED, LOCKED, RESTRICTED };

class Area{
    private:
        AreaStatus status;

    public:
        Area(AreaStatus s = AreaStatus::UNLOCKED);
        AreaStatus getStatus() const;
        void setStatus(AreaStatus s);
};


#endif //AREA_H