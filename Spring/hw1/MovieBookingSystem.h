// Ahmet Faruk Ulutas - CS 201-1 - 21803717

#ifndef MovieBookingSystem_h
#define MovieBookingSystem_h

#include "Movie.h"
#include "Reservation.h"

class MovieBookingSystem{
public:
    const static int numOfRow = 30;
    const static int numOfColumn = 26;
    MovieBookingSystem();
    ~MovieBookingSystem();
    void addMovie( const long movieID, const int audienceRadius );
    void cancelMovie( const long movieID);
    void showAllMovies();
    void showMovie( const long movieID);
    int makeReservation( const long movieID, const int row, const char col);
    int findMovieIndex( const long movieID);
    void cancelReservations( const int numRes,const int* resCode);
    void showReservation( const int resCode);
    bool checkMovieID( const long movieID);
    bool checkOccupiable( const long movieID, const int row, const int col);
    bool checkAvailable( const long movieID, const int row, const char col);
    int numberOfMovies;
    int numberOfRes;
    int uniqueResCode;
    Movie* movieList;
    Reservation* resList;

private:
// ...
//you may define additional member functions and data members, if necessary.

};

#endif
