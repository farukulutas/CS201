// Ahmet Faruk Ulutas - CS 201-3 - 21803717

#ifndef Book_h
#define Book_h

#include <string>

using namespace std;

// to make ID's unique
class Book {
private:
    int id;
    string title;
    int year;

public:
    Book( int id, string name, int year);
    Book();
    ~Book();

    // getters
    string getTitle();
    int getYear();
    int getId();

    // setters
    void setName( string title);
	void setId( int id);
	void setYear( int year);
};

#endif
