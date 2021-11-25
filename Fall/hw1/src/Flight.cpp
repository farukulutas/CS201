// Ahmet Faruk Ulutas - 21803717
#include "Flight.h"
#include <iostream>

using namespace std;

// Constructors
Flight::Flight(int flightNumber, int rowNumber, int colNumber) {
    this->flightNo = flightNumber;
    this->rowNo = rowNumber;
    this->colNo = colNumber;
    this->totalReservations = 0;
}

Flight::Flight() {
    this->flightNo = 0;
    this->rowNo = 0;
    this->colNo = 0;
    this->totalReservations = 0;
}

// Deconstructor
Flight::~Flight(){ }

// Methods

// This method calculate total seats in a flight and return it
int Flight::totalSeatsInFlight() {
    return this->rowNo * this->colNo;
}

// Getter and Setter Methods
void Flight::setFlightNo(int newFlightNumber) {
    this->flightNo = newFlightNumber;
}

void Flight::setRowNo(int newRowNumber) {
    this->rowNo = newRowNumber;
}

void Flight::setColNo(int newColNumber) {
    this->colNo = newColNumber;
}

void Flight::setTotalReservations(int totalReservations) {
    this->totalReservations = totalReservations;
}

int Flight::getFlightNo() {
    return this->flightNo;
}

int Flight::getRowNo() {
    return this->rowNo;
}

int Flight::getColNo() {
    return this->colNo;
}

int Flight::getTotalReservations() {
    return this->totalReservations;
}
