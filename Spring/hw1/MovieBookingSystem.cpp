// Ahmet Faruk Ulutas - CS 201-1 - 21803717
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

#include "MovieBookingSystem.h"

MovieBookingSystem::MovieBookingSystem() {
    this->numberOfMovies = 0;
    this->movieList = NULL;
    this->numberOfRes = 0;
    this->uniqueResCode = 1;
    this->resList = NULL;
}

MovieBookingSystem::~MovieBookingSystem() {
    delete[] movieList;
    delete[] resList;
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
        Movie* tempList = new Movie[ this->numberOfMovies + 1];

        for ( int i = 0; i < this->numberOfMovies; i++ ) {
            tempList[i] = this->movieList[i];
        }

        tempList[numberOfMovies].setAudienceRadius( audienceRadius);
        tempList[numberOfMovies].setMovieID( movieID);
        tempList[numberOfMovies].setNumberOfRows( (29) / (audienceRadius + 1) + 1);
        tempList[numberOfMovies].setNumberOfCols( (25) / (audienceRadius + 1) + 1);
        tempList[numberOfMovies].setNumberOfAvailableSeats( tempList[numberOfMovies].getNumberOfCols() * tempList[numberOfMovies].getNumberOfRows() );

        Seats** seats = new Seats*[ tempList[numberOfMovies].getNumberOfRows()];

        for ( int a = 0; a < tempList[numberOfMovies].getNumberOfRows(); ++a ) {
            seats[a] = new Seats[ tempList[numberOfMovies].getNumberOfCols()];
        }

        tempList[numberOfMovies].setSeats( seats);

        delete[] movieList;
        this->movieList = tempList;
        this->numberOfMovies++;
        tempList = NULL;

        cout << "Movie at " << time << " has been added" << endl;
    }
}

bool MovieBookingSystem::checkMovieID( long movieID) {
    for ( int i = 0; i < this->numberOfMovies; i++ ) {
        if ( this->movieList[i].getMovieID() == movieID) {
            return true;
        }
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
        int index = this->findMovieIndex( movieID);
        Movie* temp = new Movie[numberOfMovies - 1];

        for ( int j = 0; j < index; j++ ) {
            temp[j] = this->movieList[j];
        }

        for ( int k = index; k < numberOfMovies - 1; k++) {
            temp[k] = this->movieList[k + 1];
        }

        delete[] movieList;
        this->movieList = temp;
        temp = NULL;
        this->numberOfMovies--;

        cout << "Movie at " << time << " has been canceled" << endl;
    }
}

void MovieBookingSystem::showAllMovies() {
    if ( numberOfMovies == 0 ) {
        cout << "No movie on show" << endl;
    }
    else {
        cout << "Movies on show:" << endl;

        for ( int i = 0; i < numberOfMovies; i++ ) {
            time_t rawtime = movieList[i].getMovieID();
            string time = ctime(&rawtime);
            time.erase(time.find('\n', 0), 1);
            cout << "Movie at " << time << " (" << movieList[i].getNumberOfAvailableSeats() << " available seats)" << endl;
        }
    }
}

void MovieBookingSystem::showMovie( const long movieID) {
    int asciiVal = 65;
    int rowNo = 1;
    int index = this->findMovieIndex( movieID);

    time_t rawtime = movieID;
    string time = ctime(&rawtime);
    time.erase(time.find('\n', 0), 1);
    cout << "Movie at " << time << " has " << this->movieList[index].getNumberOfAvailableSeats() << " available seats" << endl;

    for ( int i = 0; i < this->movieList[index].getNumberOfRows() + 1; i++ ) {
        for ( int j = 0; j < this->movieList[index].getNumberOfCols() + 1; j++ ) {
            if ( i == 0 ) {
                if ( j == 0 ) {
                    cout << "   ";
                }
                else {
                    cout << char(asciiVal) << " ";
                    asciiVal = asciiVal + this->movieList[index].getAudienceRadius() + 1;
                }
            }
            else {
                if ( j == 0 ) {
                    if ( rowNo < 10 ) {
                        cout << " ";
                    }
                    cout << rowNo << " ";
                    rowNo = rowNo + this->movieList[index].getAudienceRadius() + 1;
                }
                else {
                    if ( this->movieList[index].getSeats()[i - 1][j - 1].getSeatStatus() ) {
                        cout << "o ";
                    }
                    else {
                        if ( this->movieList[index].getMovieID() == movieID ) {
                            cout << "x ";
                        }
                    }
                }
            }
        }

        cout << endl;
    }
}

int MovieBookingSystem::makeReservation( const long movieID, const int row, const char col) {
    const int column = col - 65;
    const int rowumn = row - 1;
    time_t rawtime = movieID;
    string time = ctime(&rawtime);
    time.erase(time.find('\n', 0), 1);

    if ( !this->checkMovieID( movieID) ) {
        cout << "Movie at " << time << " does not exist" << endl;
    }
    else if ( !checkOccupiable( movieID, row, column + 1) ) {
        cout << "Seat " << col << row << " is not occupiable in Movie at " << time << endl;
    }
    else if ( !checkAvailable( movieID, row, col) ) {
        cout << "Seat " << col << row << " is not available in Movie at " << time << endl;
    }
    else {
        int index = this->findMovieIndex(movieID);
        int realRow = rowumn / this->movieList[index].getAudienceRadius();
        int realCol = column / this->movieList[index].getAudienceRadius();

        if ( column % this->movieList[index].getAudienceRadius() == 0 && realCol != 0 ) {
            realCol = realCol - 1;
        }

        this->movieList[index].getSeats()[realRow][realCol].setSeatStatus( false);
        this->movieList[index].setNumberOfAvailableSeats( this->movieList[index].getNumberOfAvailableSeats() - 1);
        cout << "Reservation done for " << col << row << " in Movie at " << time << endl;
        numberOfRes++;
        Reservation* tempList = new Reservation[ this->numberOfRes];

        for ( int i = 0; i < numberOfRes - 1; i++ ) {
            tempList[i] = this->resList[i];
        }

        tempList[numberOfRes - 1].setColNo( col);
        tempList[numberOfRes - 1].setRowNo( row);
        tempList[numberOfRes - 1].setResCode( uniqueResCode);
        tempList[numberOfRes - 1].setMovieID( movieID);

        delete[] resList;
        this->resList = tempList;
        tempList = NULL;
        uniqueResCode++;
        return this->uniqueResCode - 1;
    }

    return -1;
}

bool MovieBookingSystem::checkOccupiable( const long movieID, const int row, const int col) {
    int startingRowCol = 1;
    int index = this->findMovieIndex( movieID);
    bool rowCheck = false;
    bool colCheck = false;

    int x = this->movieList[index].getNumberOfCols();
    if ( this->movieList[index].getNumberOfRows() >= x ) {
        x = this->movieList[index].getNumberOfRows();
    }

    for ( int i = 0; i < x; i++ ) {
        if ( startingRowCol == row ) {
            rowCheck = true;
        }

        if ( startingRowCol == col) {
            colCheck = true;
        }

        startingRowCol = startingRowCol + this->movieList[index].getAudienceRadius() + 1;
    }

    if ( rowCheck && colCheck ) {
        return true;
    }

    return false;
}

bool MovieBookingSystem::checkAvailable( const long movieID, const int row, const char col) {
    bool rowCheck = false;
    bool colCheck = false;

    for ( int i = 0; i < this->numberOfRes; i++ ) {
        if ( this->resList[i].getMovieID() == movieID ) {
            if ( this->resList[i].getRowNo() == row ) {
                rowCheck = true;
            }

            if ( this->resList[i].getColNo() == col) {
                colCheck = true;
            }
        }
    }

    if ( rowCheck && colCheck ) {
        return false;
    }

    return true;
}

int MovieBookingSystem::findMovieIndex( const long movieID) {
    for ( int j = 0; j < this->numberOfMovies; j++ ) {
        if ( movieID == this->movieList[j].getMovieID() ) {
            return j;
        }
    }

    return -1;
}

void MovieBookingSystem::cancelReservations( const int numRes,const int* resCode) {
    int counter = 0;

    for ( int i = 0; i < this->numberOfRes; i++ ) {
        for ( int j = 0; j < numRes; j++ ) {
            if ( resCode[j] == this->resList[i].getResCode() ) {
                counter++;
            }
        }
    }

    if ( counter != numRes ) {
        cout << "Some reservation codes do not exist. Cancelation is failed" << endl;
    }
    else {
        for ( int k = 0; k < numRes; k++ ) {
            for ( int l = 0; l < this->numberOfRes; l++ ) {
                if ( resCode[k] == this->resList[l].getResCode() ) {
                    Reservation* temp = new Reservation[ this->numberOfRes - 1];
                    const int column = (int)(this->resList[l].getColNo() ) - 65;
                    const int rowumn = this->resList[l].getRowNo() - 1;

                    for ( int m = 0; m < l; m++ ) {
                        temp[m] = this->resList[m];
                    }

                    for ( int n = l; n < this->numberOfRes - 1; n++) {
                        temp[n] = this->resList[n + 1];
                    }

                    time_t rawtime = this->resList[l].getMovieID();
                    int index = findMovieIndex( this->resList[l].getMovieID());
                    string time = ctime(&rawtime);
                    cout << "Reservation on Code " << resCode[k] << " is canceled: Seat " << this->resList[l].getColNo() << this->resList[l].getRowNo() << " in Movie at " << time << endl;
                    delete[] resList;
                    this->resList = temp;
                    temp = NULL;
                    this->numberOfRes--;
                    this->movieList[index].setNumberOfAvailableSeats( this->movieList[index].getNumberOfAvailableSeats() + 1);
                    int realRow = rowumn / this->movieList[index].getAudienceRadius();
                    int realCol = column / this->movieList[index].getAudienceRadius();
                    this->movieList[index].getSeats()[realRow][realCol].setSeatStatus( true);
                }
            }
        }
    }
}

void MovieBookingSystem::showReservation( const int resCode) {
    int counter = 0;
    int index = 0;

    for ( int i = 0; i < numberOfRes; i++ ) {
        if ( resList[i].getResCode() == resCode ) {
            counter++;
            index = i;
            break;
        }
    }

    if ( counter == 1 ) {
        time_t rawtime = resList[index].getMovieID();
        string time = ctime(&rawtime);
        cout << "Reservation with Code " << resCode << ": Seat " << resList[index].getColNo() << resList[index].getRowNo() << " in Movie at " << time << endl;
    }
    else {
        cout << "No reservation with Code " << resCode << endl;
    }
}
