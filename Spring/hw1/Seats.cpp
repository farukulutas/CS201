// Ahmet Faruk Ulutas - CS 201-1 - 21803717
#include <iostream>
#include <string>

using namespace std;

#include "Seats.h"

Seats::Seats() {
    this->seatStatus = true; // means available to reservation
}

Seats::~Seats() {
}

bool Seats::getSeatStatus() {
    return this->seatStatus;
}

void Seats::setSeatStatus( bool seatStatus) {
    this->seatStatus = seatStatus;
}
