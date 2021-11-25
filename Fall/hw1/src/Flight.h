// Ahmet Faruk Ulutas - 21803717
#ifndef FLIGHT_H
#define FLIGHT_H

class Flight {
    public:
        // Constructors
        Flight(int flightNumber, int rowNumber, int colNumber);
        Flight();
        ~Flight();

        // Methods
        int totalSeatsInFlight();

        // Getters & Setters increment
        void setFlightNo(int flightNo);
        void setRowNo(int rowNo);
        void setColNo(int colNo);
        void setTotalReservations(int totalReservations);
        int getFlightNo();
        int getRowNo();
        int getColNo();
        int getTotalReservations();

    private:
        // Variables
        int flightNo;
        int rowNo;
        int colNo;
        int totalReservations;
};

#endif // FLIGHT_H
