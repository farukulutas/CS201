// Ahmet Faruk Ulutas - CS 201-1 - 21803717

#ifndef Reservation_h
#define Reservation_h

class Reservation{
public:
    Reservation( long movieID, int resCode, int rowNo, char colNo);
    Reservation();
    ~Reservation();
    long getMovieID();
    int getResCode();
    int getRowNo();
    char getColNo();
    void setMovieID( long movieID);
    void setResCode( int resCode);
    void setRowNo( int rowNo);
    void setColNo( char colNo);

private:
    // ...
    //you may define additional member functions and data members, if necessary.
    long movieID;
    int resCode;
    int rowNo;
    char colNo;
};

#endif
