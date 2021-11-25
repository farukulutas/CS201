// Ahmet Faruk Ulutas - 21803717

#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H
#include "Flight.h"
#include "Reservation.h"
#include <iostream>

class ReservationSystem {
    public:
        // Constructors
        ReservationSystem();
        ~ReservationSystem();

        // Methods
        void addFlight( const int flightNo, const int rowNo, const int seatNo );
        void cancelFlight( const int flightNo );
        void showAllFlights();
        void showFlight( const int flightNo );
        int makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol );
        void cancelReservation( const int resCode );
        void showReservation( const int resCode );
        void printDetailedInformation( int flightNo);
        bool isReserved( const int flightNo);
        bool isReserved(const int flightNo, const int rowInput, const int colInput);

    private:
        // Variables
        int numberOfFlights;
        int numberOfReservations;
        Flight* flightsArray;
        Reservation* reservationsArray;
};

#endif // RESERVATIONSYSTEM_H
