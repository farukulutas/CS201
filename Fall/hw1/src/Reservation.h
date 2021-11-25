// Ahmet Faruk Ulutas - 21803717
#ifndef RESERVATION_H
#define RESERVATION_H
#include "Flight.h"

class Reservation
{
    public:
        // Constructors
        Reservation();
        ~Reservation();

        // Methods
        void setFlightNo(int flightNo);
        void setResCode(int resCode);
        void setPassengerNo(int passengerNo);
        void setRowNo(int rowNo);
        void setColNo(int colNo);
        int getFlightNo();
        int getResCode();
        int getPassengerNo();
        int getRowNo();
        int getColNo();

    private:
        // Variables
        int flightNo = 0;
        int resCode = 0;
        int passengerNo = 0;
        int rowNo = 0;
        int colNo = 0;
};

#endif // RESERVATION_H
