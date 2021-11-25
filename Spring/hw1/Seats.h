// Ahmet Faruk Ulutas - CS 201-1 - 21803717

#ifndef Seats_h
#define Seats_h

class Seats{
public:
    Seats();
    ~Seats();
    bool getSeatStatus();
    void setSeatStatus( bool seatStatus);

private:
// ...
//you may define additional member functions and data members, if necessary.
    bool seatStatus;
};

#endif
