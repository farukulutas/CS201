// Ahmet Faruk Ulutas - CS 201-1 - 21803717
#include <iostream>
#include <string>

using namespace std;

#include "Reservation.h"

Reservation::Reservation( long movieID, int resCode, int rowNo, char colNo) {
    this->movieID = movieID;
    this->resCode = resCode;
    this->rowNo = rowNo;
    this->colNo = colNo;
}

Reservation::Reservation() {
    this->movieID = 0;
    this->resCode = 0;
    this->rowNo = 0;
    this->colNo = 0;
}

Reservation::~Reservation() {
}

long Reservation::getMovieID() {
    return this->movieID;
}

int Reservation::getResCode() {
    return this->resCode;
}

int Reservation::getRowNo() {
    return this->rowNo;
}

char Reservation::getColNo() {
    return this->colNo;
}

void Reservation::setMovieID( long movieID) {
    this->movieID = movieID;
}

void Reservation::setResCode( int resCode) {
    this->resCode = resCode;
}

void Reservation::setRowNo( int rowNo) {
    this->rowNo = rowNo;
}

void Reservation::setColNo( char colNo) {
    this->colNo = colNo;
}
