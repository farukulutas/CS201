// Ahmet Faruk Ulutas - CS 201-1 - 21803717
#ifndef MovieBookingSystem_h
#define MovieBookingSystem_h

#include "Movie.h"
#include "Reservation.h"
#include "ReservationList.h"

class MovieBookingSystem{
public:
    const static int numOfRow = 30;
    const static int numOfColumn = 26;
    MovieBookingSystem();
    ~MovieBookingSystem();
    void addMovie( const long movieID, const int audienceRadius );
    bool checkMovieID( long movieID);
    void cancelMovie( const long movieID);
    void showAllMovies() const;
    void showMovie( const long movieID) const;
    int makeReservation( const long movieID, const int row, const char
    col);
    bool checkOccupiable( const long movieID, const int row, const int col);
    bool checkAvailable( const long movieID, const int row, const char col);
    void cancelReservations( ReservationList resCode);
    void showReservation( const int resCode) const;
private:
    ReservationList reservationCodes;
    struct ReservationNode{
        ReservationNode* next;
        Reservation res;
    };
    struct MovieNode{
        MovieNode* next;
        Movie m;
    };
    int reservationSize;
    int movieSize;
    MovieNode* movieHead;
    ReservationNode* reservationHead;
    int uniqueResCode;
    // ...
    //you may define additional member functions and data members, if necessary.
};

#endif

