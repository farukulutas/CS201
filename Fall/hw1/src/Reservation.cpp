// Ahmet Faruk Ulutas - 21803717
#include "Reservation.h"
#include <iostream>

using namespace std;

// Constructor
Reservation::Reservation() {
    flightNo = 0;
    resCode = 0;
    passengerNo = 0;
    rowNo = 0;
    colNo = 0;
}

// Destructor
Reservation::~Reservation() { }

// Methods

// Get and Set Methods
void Reservation::setFlightNo(int flightNo) {
    this->flightNo = flightNo;
}

void Reservation::setResCode(int resCode) {
    this->resCode = resCode;
}

void Reservation::setPassengerNo(int passengerNo) {
    this->passengerNo = passengerNo;
}

void Reservation::setRowNo(int rowNo) {
    this->rowNo = rowNo;
}

void Reservation::setColNo(int colNo) {
    this->colNo = colNo;
}

int Reservation::getFlightNo() {
    return this->flightNo;
}

int Reservation::getResCode() {
    return this->resCode;
}

int Reservation::getPassengerNo() {
    return this->passengerNo;
}

int Reservation::getRowNo() {
    return this->rowNo;
}

int Reservation::getColNo() {
    return this->colNo;
}
