// Ahmet Faruk Ulutas - CS 201-1 - 21803717

#ifndef Movie_h
#define Movie_h

#include "Seats.h"

class Movie{
public:
    Movie( long movieID, int audienceRadius);
    Movie();
    ~Movie();
    void checkMovieID( const long movieID, const int audienceRadius );
    long getMovieID();
    int getNumberOfAvailableSeats();
    int getNumberOfRows();
    int getNumberOfCols();
    int getAudienceRadius();
    Seats** getSeats();
    void setMovieID( long movieID);
    void setNumberOfAvailableSeats( int numberOfAvailableSeats);
    void setNumberOfRows( int numberOfRows);
    void setNumberOfCols( int numberOfCols);
    void setAudienceRadius( int audienceRadius);
    void setSeats( Seats** seats);

private:
// ...
//you may define additional member functions and data members, if necessary.
    long movieID;
    int audienceRadius;
    int numberOfAvailableSeats;
    int numberOfRows;
    int numberOfCols;
    Seats** seats;
};

#endif
