// Ahmet Faruk Ulutas - CS 201-1 - 21803717
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

#include "MovieBookingSystem.h"
#include <cstddef>

MovieBookingSystem::MovieBookingSystem(): reservationSize(0), movieSize(0), movieHead(NULL), reservationHead(NULL), uniqueResCode(1) {

}

MovieBookingSystem::~MovieBookingSystem() {
    MovieNode* current = movieHead;
    while( current != NULL ) {
        MovieNode* next = current->next;
        delete current;
        current = next;
    }

    ReservationNode* current2 = reservationHead;
    while( current2 != NULL ) {
        ReservationNode* next2 = current2->next;
        delete current2;
        current2 = next2;
    }

    movieHead = NULL;
    reservationHead = NULL;
}

void MovieBookingSystem::addMovie( const long movieID, const int audienceRadius) {
    time_t rawtime = movieID;
    string time = ctime(&rawtime);
    time.erase(time.find('\n', 0), 1);

    if ( this->checkMovieID( movieID) ) {
        cout << "Movie at " << time << " already exists" << endl;
    }
    else if ( audienceRadius > 7 || audienceRadius < 0 ) {
        cout << "Audience radius should be in range [0,7]." << endl;
    }
    else {
        Movie mov = Movie( movieID, audienceRadius);
        MovieNode *movNode = new MovieNode;
        movNode->m = mov;
        movNode->next = NULL;

        if ( movieSize <= 0 ) {
            movieHead = movNode;
        }
        else {
            MovieNode *cur = new MovieNode;
            cur = movieHead;
            for ( int i = 0; i < movieSize - 1; i++ ) {
                cur = cur->next;
            }

            cur->next = movNode;
        }

        movieSize++;
        cout << "Movie at " << time << " has been added" << endl;
    }
}

bool MovieBookingSystem::checkMovieID( long movieID) {
    for ( MovieNode *cur = movieHead; cur != NULL; cur = cur->next ) {
        if ( cur->m.getMovieID() == movieID )
            return true;
    }

    return false;
}

void MovieBookingSystem::cancelMovie( const long movieID) {
    time_t rawtime = movieID;
    string time = ctime(&rawtime);
    time.erase(time.find('\n', 0), 1);

    if ( !this->checkMovieID( movieID) ) {
        cout << "Movie at " << time << " does not exist" << endl;
    }
    else {
        MovieNode *cur = movieHead;
        MovieNode *prev = NULL;
        --movieSize;

        if ( movieSize == 1 ) {
            movieHead = NULL;
        }
        else {
            while ( cur != NULL ) {
                if ( cur->m.getMovieID() == movieID ) {
                    break;
                }
                prev = cur;
                cur = cur->next;
            }

            prev->next = prev->next->next;
            delete cur;
            cur = NULL;
        }

        cout << "Movie at " << time << " has been canceled" << endl;
    }
}

void MovieBookingSystem::showAllMovies() const {
    if ( movieSize == 0 ) {
        cout << "No movie on show" << endl;
    }
    else {
        cout << "Movies on show:" << endl;

        for ( MovieNode *cur = movieHead; cur != NULL; cur = cur->next ) {
            time_t rawtime = cur->m.getMovieID();
            string time = ctime(&rawtime);
            time.erase(time.find('\n', 0), 1);
            cout << "Movie at " << time << " (" << cur->m.getNumberOfAvailableSeats() << " available seats)" << endl;
        }
    }
}

void MovieBookingSystem::showMovie( const long movieID) const {
    int asciiVal = 65;
    int rowNo = 1;
    MovieNode *cur = movieHead;
    bool isO = false;

    while ( cur != NULL ) {
        if ( cur->m.getMovieID() == movieID ) {
            break;
        }

        cur = cur->next;
    }

    time_t rawtime = movieID;
    string time = ctime(&rawtime);
    time.erase(time.find('\n', 0), 1);
    cout << "Movie at " << time << " has " << cur->m.getNumberOfAvailableSeats() << " available seats" << endl;

    for ( int i = 0; i < cur->m.getNumberOfRows() + 1; i++ ) {
        for ( int j = 0; j < cur->m.getNumberOfCols() + 1; j++ ) {
            isO = false;

            if ( i == 0 ) {
                if ( j == 0 ) {
                    cout << "   ";
                }
                else {
                    cout << char(asciiVal) << " ";
                    asciiVal = asciiVal + cur->m.getAudienceRadius() + 1;
                }
            }
            else {
                if ( j == 0 ) {
                    if ( rowNo < 10 ) {
                        cout << " ";
                    }
                    cout << rowNo << " ";
                    rowNo = rowNo + cur->m.getAudienceRadius() + 1;
                }
                else {
                    ReservationNode *curRes = reservationHead;
                    for ( int m = 0; m < reservationSize; m++ ) {
                        if ( curRes->res.getMovieID() == movieID && curRes->res.getRowNo() == (1 + (i - 1) * (cur->m.getAudienceRadius() + 1)) && ((int)(curRes->res.getColNo()) - 64) == (1 + (j - 1) * (cur->m.getAudienceRadius() + 1)) ) {
                            cout << "o ";
                            isO = true;
                            break;
                        }
                    }

                    if ( !isO )
                        cout << "x ";
                }
            }
        }

        cout << endl;
    }
}

int MovieBookingSystem::makeReservation( const long movieID, const int row, const char col) {
    const int column = col - 65;
    time_t rawtime = movieID;
    string time = ctime(&rawtime);
    time.erase(time.find('\n', 0), 1);

    if ( !checkMovieID( movieID) ) {
        cout << "Movie at " << time << " does not exist" << endl;
    }
    else if ( !checkOccupiable( movieID, row, column + 1) ) {
        cout << "Seat " << col << row << " is not occupiable in Movie at " << time << endl;
    }
    else if ( !checkAvailable( movieID, row, col) ) {
        cout << "Seat " << col << row << " is not available in Movie at " << time << endl;
    }
    else {
        Reservation r = Reservation( movieID, uniqueResCode, row, col);
        ReservationNode *rNode = new ReservationNode;
        rNode->res = r;
        rNode->next = NULL;

        for ( MovieNode *curr = movieHead; curr != NULL; curr = curr->next ) {
            if ( curr->m.getMovieID() == movieID ) {
                curr->m.setNumberOfAvailableSeats( curr->m.getNumberOfAvailableSeats() - 1 );
                break;
            }
        }

        if ( reservationSize == 0 ) {
            reservationHead = rNode;
        }
        else {
            ReservationNode *curNode = reservationHead;
            for ( int l = 0; l < reservationSize - 1; l++ ) {
                curNode = curNode->next;
            }

            curNode->next = rNode;
        }

        reservationSize++;
        cout << "Reservation done for " << col << row << " in Movie at " << time << endl;
        uniqueResCode++;
        return this->uniqueResCode - 1;
    }

    return -1;
}

bool MovieBookingSystem::checkOccupiable( const long movieID, const int row, const int col) {
    int startingRowCol = 1;
    bool rowCheck = false;
    bool colCheck = false;
    MovieNode *mov;

    for ( MovieNode *curr = movieHead; curr != NULL; curr = curr->next ) {
            if ( curr->m.getMovieID() == movieID ) {
                mov = curr;
                break;
            }
    }

    int x = mov->m.getNumberOfCols();
    if ( mov->m.getNumberOfRows() >= x ) {
        x = mov->m.getNumberOfRows();
    }

    for ( int i = 0; i < x; i++ ) {
        if ( startingRowCol == row ) {
            rowCheck = true;
        }

        if ( startingRowCol == col) {
            colCheck = true;
        }

        startingRowCol = startingRowCol + mov->m.getAudienceRadius() + 1;
    }

    if ( rowCheck && colCheck ) {
        return true;
    }

    return false;
}

bool MovieBookingSystem::checkAvailable( const long movieID, const int row, const char col) {
    bool rowCheck = false;
    bool colCheck = false;

    for ( ReservationNode *curr = reservationHead; curr != NULL; curr = curr->next ) {
        if ( curr->res.getMovieID() == movieID ) {
            if ( curr->res.getRowNo() == row ) {
                rowCheck = true;
            }

            if ( curr->res.getColNo() == col) {
                colCheck = true;
            }
        }
    }

    if ( rowCheck && colCheck ) {
        return false;
    }

    return true;
}

void MovieBookingSystem::cancelReservations( ReservationList resCode) {
    int count = 0;
    int rescode = 0;
    int rescode2 = 0;

    for ( int k = 0; k < resCode.getLength(); k++ ) {
        resCode.retrieve( k, rescode);

        for ( int l = 0; l < reservationSize; l++ ) {
            reservationCodes.retrieve( l, rescode2);
            if ( rescode == rescode2 ) {
                count++;
            }
        }
    }

    if ( count != resCode.getLength() ) {
        cout << "Some reservation codes do not exist. Cancelation is failed" << endl;
    }
    else {
        ReservationNode *cur = reservationHead;

        for ( int i = 0; i <= resCode.getLength(); i++ ) {
            resCode.retrieve( i, rescode);

            for ( int j = 1; j <= reservationSize; j++ ) {
                reservationCodes.retrieve( j, rescode2);
                if ( rescode == rescode2 ) {
                    time_t rawtime = cur->res.getMovieID();
                    string time = ctime(&rawtime);
                    cout << "Reservation on Code " << rescode2 << " is canceled: Seat " << cur->res.getColNo() << cur->res.getRowNo() << " in Movie at " << time << endl;
                    reservationCodes.remove(j);
                    resCode.remove(i);
                    reservationSize--;
                }

                cur = cur->next;
            }
        }
    }
}

void MovieBookingSystem::showReservation( const int resCode) const {
    int counter = 0;
    ReservationNode *reserv;
    for ( ReservationNode *cur = reservationHead; cur != NULL; cur = cur->next ) {
        if ( cur->res.getResCode() == resCode) {
            counter++;
            reserv = cur;
            break;
        }
    }

    if ( counter == 1 ) {
        time_t rawtime = reserv->res.getMovieID();
        string time = ctime(&rawtime);
        cout << "Reservation with Code " << resCode << ": Seat " << reserv->res.getColNo() << reserv->res.getRowNo() << " in Movie at " << time << endl;
    }
    else {
        cout << "No reservation with Code " << resCode << endl;
    }
}

