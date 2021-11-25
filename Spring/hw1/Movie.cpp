// Ahmet Faruk Ulutas - CS 201-1 - 21803717
#include <iostream>
#include <string>

using namespace std;

#include "Movie.h"

Movie::Movie( long movieID, int audienceRadius) {
    this->movieID = movieID;
    this->audienceRadius = audienceRadius;
    this->numberOfRows = (29) / (audienceRadius + 1) + 1;
    this->numberOfCols = (25) / (audienceRadius + 1) + 1;
    this->numberOfAvailableSeats = numberOfRows * numberOfCols;

    this->seats = new Seats*[ numberOfRows];

    for ( int a = 0; a < numberOfRows; ++a ) {
        this->seats[a] = new Seats[ numberOfCols];
    }
}

Movie::Movie() {
    this->movieID = 0;
    this->audienceRadius = 0;
    this->seats = NULL;
    this->numberOfRows = 0;
    this->numberOfCols = 0;
    this->numberOfAvailableSeats = 0;
}

Movie::~Movie() {
}

long Movie::getMovieID() {
    return this->movieID;
}

int Movie::getNumberOfAvailableSeats() {
    return this->numberOfAvailableSeats;
}

int Movie::getNumberOfRows() {
    return this->numberOfRows;
}

int Movie::getNumberOfCols() {
    return this->numberOfCols;
}

int Movie::getAudienceRadius() {
    return this->audienceRadius;
}

Seats** Movie::getSeats() {
    return this->seats;
}

void Movie::setMovieID( long movieID) {
    this->movieID = movieID;
}

void Movie::setNumberOfAvailableSeats( int numberOfAvailableSeats) {
    this->numberOfAvailableSeats = numberOfAvailableSeats;
}

void Movie::setNumberOfRows( int numberOfRows) {
    this->numberOfRows = numberOfRows;
}

void Movie::setNumberOfCols( int numberOfCols) {
    this->numberOfCols = numberOfCols;
}

void Movie::setAudienceRadius( int audienceRadius) {
    this->audienceRadius = audienceRadius;
}

void Movie::setSeats( Seats** seats) {
    this->seats = seats;
}
