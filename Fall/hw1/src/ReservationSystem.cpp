// Ahmet Faruk Ulutas - 21803717
#include "ReservationSystem.h"

using namespace std;

// Constructor
ReservationSystem::ReservationSystem() {
    numberOfFlights = 0;
    numberOfReservations = 0;
    flightsArray = NULL;
    reservationsArray = NULL;
}

// Deconstructor
ReservationSystem::~ReservationSystem() {
    if ( flightsArray != NULL) {
        delete[] flightsArray;
    }

    if ( reservationsArray != NULL ) {
        delete[] reservationsArray;
    }
}

// Methods

/* This method add new flights with the unique flight number. If exists it
gives and error. */
void ReservationSystem::addFlight( const int flightNo, const int rowNo, const int seatNo ) {
    if ( rowNo > 0 && seatNo > 0 ) {
        if ( flightsArray == NULL ) {
            numberOfFlights = 1;

            flightsArray = new Flight[ numberOfFlights];

            flightsArray[numberOfFlights].setFlightNo( flightNo);
            flightsArray[numberOfFlights].setRowNo( rowNo);;
            flightsArray[numberOfFlights].setColNo( seatNo);

            cout << "Flight " << flightNo << " has been added" << endl;
        }
        else {
            bool checkFlightNo;

            checkFlightNo = true;

            for ( int i = 0; i < numberOfFlights; i++ ) {
                if( flightsArray[i].getFlightNo() == flightNo ) {
                    checkFlightNo = false;
                }
            }

            if ( !checkFlightNo ) {
                cout << "Flight " << flightNo << " already exists" << endl;
            }
            else {
                Flight* temp;

                temp = new Flight[ numberOfFlights];

                for ( int i = 0; i < numberOfFlights; i++ ) {
                    temp[i].setFlightNo( flightsArray[i].getFlightNo() );
                    temp[i].setRowNo( flightsArray[i].getRowNo() );
                    temp[i].setColNo( flightsArray[i].getColNo() );
                }

                delete[] flightsArray;

                flightsArray = new Flight[ numberOfFlights + 1];

                for ( int j = 0; j < numberOfFlights; j++ ) {
                    flightsArray[j].setFlightNo( temp[j].getFlightNo() );
                    flightsArray[j].setRowNo( temp[j].getRowNo() );
                    flightsArray[j].setColNo( temp[j].getColNo() );
                }

                flightsArray[numberOfFlights].setFlightNo( flightNo);
                flightsArray[numberOfFlights].setRowNo( rowNo);;
                flightsArray[numberOfFlights].setColNo( seatNo);

                cout << "Flight " << flightNo << " has been added" << endl;

                numberOfFlights++;

                delete[] temp;
            }
        }
    }
    else {
        cout << "Row number and seat number must be positive!";
    }
}

/* This method cancel existing flight and its reservations by using
unique flight number. */
void ReservationSystem::cancelFlight( const int flightNo ) {
    bool isFlightNoExist;
    int reservationCounter, index;

    isFlightNoExist = false;
    reservationCounter = 0;
    index = 0;

    for ( int i = 0; i < numberOfFlights; i++ ) {
        if ( flightsArray[i].getFlightNo() == flightNo ) {
            isFlightNoExist = true;
        }
    }

    for ( int b = 0; b < numberOfReservations; b++ ) {
        if ( reservationsArray[b].getFlightNo() == flightNo ) {
            reservationCounter++;
        }
    }

    if ( isFlightNoExist ) {
        Flight* temp;
        Reservation* tempRes;

        numberOfFlights--;
        numberOfReservations = numberOfFlights - reservationCounter;

        temp = new Flight[ numberOfFlights];
        tempRes = new Reservation[ numberOfReservations];

        for ( int k = 0; k < numberOfFlights + 1; k++ ) {
            if ( flightsArray[k].getFlightNo() != flightNo ) {
                temp[index].setFlightNo( flightsArray[k].getFlightNo() );
                temp[index].setRowNo( flightsArray[k].getRowNo() );
                temp[index].setColNo( flightsArray[k].getColNo() );
                temp[index].setTotalReservations( flightsArray[k].getTotalReservations() );

                index++;
            }
        }

        index = 0;

        for ( int c = 0; c < numberOfReservations + reservationCounter; c++ ) {
            if ( reservationsArray[c].getFlightNo() != flightNo ) {
                tempRes[index].setFlightNo( reservationsArray[c].getFlightNo() );
                tempRes[index].setResCode( reservationsArray[c].getResCode() );
                tempRes[index].setPassengerNo( reservationsArray[c].getPassengerNo() );
                tempRes[index].setRowNo( reservationsArray[c].getRowNo() );
                tempRes[index].setColNo( reservationsArray[c].getColNo() );

                index++;
            }
        }

        delete[] flightsArray;
        delete[] reservationsArray;

        flightsArray = new Flight[ numberOfFlights];
        reservationsArray = new Reservation[ numberOfReservations];

        for ( int j = 0; j < numberOfFlights; j++ ) {
            flightsArray[j].setFlightNo( temp[j].getFlightNo() );
            flightsArray[j].setRowNo( temp[j].getRowNo() );
            flightsArray[j].setColNo( temp[j].getColNo() );
            flightsArray[j].setTotalReservations( temp[j].getTotalReservations() );
        }

        for ( int d = 0; d < numberOfFlights; d++ ) {
            reservationsArray[d].setFlightNo( tempRes[d].getFlightNo() );
            reservationsArray[d].setResCode( tempRes[d].getResCode() );
            reservationsArray[d].setPassengerNo( tempRes[d].getPassengerNo() );
            reservationsArray[d].setRowNo( tempRes[d].getRowNo() );
            reservationsArray[d].setColNo( tempRes[d].getColNo() );
        }

        cout << "Flight " << flightNo << " and all of its reservations are canceled" << endl;

        delete[] temp;
        delete[] tempRes;
    }
    else {
        cout << "Flight " << flightNo << " does not exist" << endl;
    }
}

/* This method shows all available flights and unique flight number with
the available seats. */
void ReservationSystem::showAllFlights() {
    if ( numberOfFlights == 0 ) {
        cout << "No flights exist" << endl;
    }
    else {
        cout << "Flights currently operated:" << endl;

        for ( int i = 0; i < numberOfFlights; i++ ) {
            cout << "Flight " << flightsArray[i].getFlightNo() << " (" << flightsArray[i].totalSeatsInFlight() - flightsArray[i].getTotalReservations() << " available seats)" << endl;
        }
    }
}

/* This method takes and flight number and print the available seats with the
detailed format if the flight exists. */
void ReservationSystem::showFlight( const int flightNo ) {
    bool check;

    check = false;

    if( numberOfFlights == 0) {
        cout << "No flight exists" << endl;
    }
    else {
        for ( int i = 0 ; i < numberOfFlights; i++ ) {
            if( flightsArray[i].getFlightNo() == flightNo ) {
                cout << "Flight " << flightNo << " has " << flightsArray[i].totalSeatsInFlight() - flightsArray[i].getTotalReservations() <<  " available seats" << endl;
                printDetailedInformation(flightNo);
                check = true;
                break;
            }
        }

        if( !check)
        {
            cout << "Flight " << flightNo << " does not exist." << endl;
        }
    }
}

/* This method makes an reservation for the flight which has unique number
if the seats available for the passengers. */
int ReservationSystem::makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol ) {
    bool checkFlightNo, checkReservations;
    int resCode, random;

    checkFlightNo = true;
    random = ( (double) rand() / (RAND_MAX) ) + 1;
    resCode = (int) random * flightNo * numPassengers;
    checkReservations = true;

    for ( int i = 0; i < numberOfFlights; i++ ) {
        if( flightsArray[i].getFlightNo() == flightNo ) {
            checkFlightNo = false;
        }
    }

    if ( checkFlightNo ) {
        cout << "Flight " << flightNo << " does not exist" << endl;
    }
    else {
        if ( numberOfReservations != 0 ) {
            for ( int j = 0; j < numberOfReservations; j++ ) {
                for ( int k = 0; k < numPassengers; k++ ) {
                    if ( reservationsArray[j].getFlightNo() == flightNo && reservationsArray[j].getRowNo() == seatRow[k] && reservationsArray[j].getColNo() == seatCol[k] ) {
                        checkReservations = false;
                    }
                }
            }

            if ( !checkReservations ) {
                cout << "At least one of the selected seats is not available." << endl;
                return -1;
            }
            else {
                Reservation* temp = new Reservation[ numberOfReservations];

                for ( int m = 0; m < numberOfReservations; m++ ) {
                    temp[m].setFlightNo( reservationsArray[m].getFlightNo() );
                    temp[m].setResCode( reservationsArray[m].getResCode() );
                    temp[m].setPassengerNo( reservationsArray[m].getPassengerNo() );
                    temp[m].setRowNo( reservationsArray[m].getRowNo() );
                    temp[m].setColNo( reservationsArray[m].getColNo() );
                }

                delete[] reservationsArray;

                reservationsArray = new Reservation[ numberOfReservations + numPassengers];

                for ( int n = 0; n < numberOfReservations; n++ ) {
                    reservationsArray[n].setFlightNo( temp[n].getFlightNo() );
                    reservationsArray[n].setResCode( temp[n].getResCode() );
                    reservationsArray[n].setPassengerNo( temp[n].getPassengerNo() );
                    reservationsArray[n].setRowNo( temp[n].getRowNo() );
                    reservationsArray[n].setColNo( temp[n].getColNo() );
                }

                delete[] temp;

                int indexOfFlight;

                indexOfFlight = 0;

                for ( int c = 0; c < numberOfFlights; c++ ) {
                    if ( flightNo == flightsArray[c].getFlightNo() ) {
                        indexOfFlight = c;
                    }
                }

                for ( int l = numberOfReservations; l < numPassengers; l++ ) {
                    reservationsArray[l].setFlightNo( flightNo);
                    reservationsArray[l].setResCode( resCode);
                    reservationsArray[l].setPassengerNo( numberOfReservations);
                    reservationsArray[l].setRowNo( seatRow[l]);
                    reservationsArray[l].setColNo( seatCol[l]);

                    flightsArray[ indexOfFlight].setTotalReservations( flightsArray[ indexOfFlight].getTotalReservations() + 1);
                }

                numberOfReservations = numberOfReservations + numPassengers;
            }
        }
        else {
            reservationsArray = new Reservation[ numPassengers];
            int indexOfFlight;

            indexOfFlight = 0;

            for ( int b = 0; b < numberOfFlights; b++ ) {
                if ( flightNo == flightsArray[b].getFlightNo() ) {
                    indexOfFlight = b;
                }
            }

            for ( int a = 0; a < numPassengers; a++ ) {
                reservationsArray[a].setFlightNo( flightNo);
                reservationsArray[a].setResCode( resCode);
                reservationsArray[a].setPassengerNo( numberOfReservations);
                reservationsArray[a].setRowNo( seatRow[a]);
                reservationsArray[a].setColNo( seatCol[a]);

                flightsArray[ indexOfFlight].setTotalReservations( flightsArray[ indexOfFlight].getTotalReservations() + 1);
            }

            numberOfReservations = numberOfReservations + numPassengers;
        }
    }

    return resCode;
}

/* This method cancel reservations in the flight by using unique reservation
code */
void ReservationSystem::cancelReservation( const int resCode ) {
    bool checkResCode;
    int resCounter, flightNo, indexOfFlight;

    checkResCode = false;
    resCounter = 0;
    indexOfFlight = 0;
    flightNo = 0;

    for ( int i = 0; i < numberOfReservations; i++ ) {
        if ( reservationsArray[i].getResCode() == resCode ) {
            checkResCode = true;
            flightNo = reservationsArray[i].getFlightNo();
            if ( resCounter == 0 ) {
                cout << "Reservation for the seats ";
            }

            cout << reservationsArray[i].getRowNo() << (char) reservationsArray[i].getColNo() << " ";
            resCounter++;
        }
    }

    cout << "is cancelled in Flight" << flightNo << endl;

    if ( !checkResCode ) {
        cout << "No reservations under Code " << resCode << endl;
    }
    else {
        Reservation* temp = new Reservation[ numberOfReservations - resCounter];

        for ( int k = 0; k < numberOfReservations; k++ ) {
            if ( reservationsArray[k].getResCode() != resCode ) {
                temp[k].setFlightNo( reservationsArray[k].getFlightNo() );
                temp[k].setResCode( reservationsArray[k].getResCode() );
                temp[k].setPassengerNo( reservationsArray[k].getPassengerNo() );
                temp[k].setRowNo( reservationsArray[k].getRowNo() );
                temp[k].setColNo( reservationsArray[k].getColNo() );
            }
        }

        for ( int e = 0; e < numberOfFlights; e++ ) {
            if ( flightsArray[e].getFlightNo() == flightNo ) {
                indexOfFlight = e;
            }
        }

        flightsArray[ indexOfFlight].setTotalReservations( flightsArray[ indexOfFlight].getTotalReservations() - resCounter);

        delete[] reservationsArray;
        numberOfReservations = numberOfReservations - resCounter;
        reservationsArray = new Reservation[ resCounter];

        for ( int a = 0; a < numberOfReservations; a++ ) {
            reservationsArray[a].setFlightNo( temp[a].getFlightNo() );
            reservationsArray[a].setResCode( temp[a].getResCode() );
            reservationsArray[a].setPassengerNo( temp[a].getPassengerNo() );
            reservationsArray[a].setRowNo( temp[a].getRowNo() );
            reservationsArray[a].setColNo( temp[a].getColNo() );
        }

        delete[] temp;
    }
}

/* This method show the present reservations */
void ReservationSystem::showReservation( const int resCode ) {
    bool checkResCode;
    int flightNo;

    checkResCode = false;
    flightNo = 0;

    for ( int i = 0; i < numberOfReservations; i++ ) {
        if ( reservationsArray[i].getResCode() == resCode ) {
            checkResCode = true;
            flightNo = reservationsArray[i].getFlightNo();
        }
    }

    if ( !checkResCode ) {
        cout << "No reservations under Code " << flightNo << endl;
    }
    else {
        cout << "Reservations under Code " << resCode << " in Flight " << flightNo << ": ";

        for ( int i = 0; i < numberOfReservations; i++ ) {
            if ( reservationsArray[i].getResCode() == resCode ) {
                cout << reservationsArray[i].getRowNo() << (char) reservationsArray[i].getColNo() << " ";
            }
        }
    }
}

void ReservationSystem::printDetailedInformation( int flightNo) {
    char c = 'A';

    if( numberOfFlights != 0) {
        for ( int i = 0; i < numberOfFlights; i++ ) {
            if ( flightsArray[i].getFlightNo() == flightNo ) {
                for ( int j = 0; j < flightsArray[i].getColNo() + 1; j++ ) {
                    if( j == 0 ) {
                        cout << " ";
                    }
                    else {
                        cout << (char) (c + j) << " " ;
                    }
                }

                cout << endl;

                for (int j = 0; j < flightsArray[i].getRowNo(); j++ ) {
                   cout << j + 1 << " ";

                    if ( !isReserved( flightNo) ) {
                        for(int k = 0; k < flightsArray[i].getColNo(); k++) {
                            cout << "0 ";
                        }

                        cout << endl;
                    }
                    else {
                        for (int k = 0 ; k < flightsArray[i].getColNo() ; k++) {
                            if ( isReserved(flightNo, j + 1, k + 1) ) {
                                cout << "x ";
                            }
                            else {
                                cout <<"o ";
                            }
                        }

                        cout << endl;
                    }
                }

            }
        }
    }
}

bool ReservationSystem::isReserved( const int flightNo)
{
    if( numberOfReservations == 0) {
            return false;
    }

    for(int i = 0 ; i < numberOfReservations ; i++)
    {
        if( flightsArray[i].getFlightNo() == flightNo) {
                return true;
        }
    }

    return false;
}

bool ReservationSystem::isReserved(const int flightNo, const int rowInput, const int colInput)
{
    if( numberOfReservations == 0)
    {
        return false;
    }
    else
    {
        for(int i = 0 ; i < numberOfReservations ; i++)
        {
            if( flightsArray[i].getFlightNo() == flightNo)
            {
                for(int k = 0 ; k < numberOfReservations; k++)
                {
                    if( reservationsArray[k].getRowNo() == rowInput && reservationsArray[k].getColNo() == colInput)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
