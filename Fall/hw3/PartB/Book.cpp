// Ahmet Faruk Ulutas - CS 201-3 - 21803717

#include "Book.h"

using namespace std;

// Constructor
Book::Book(int id, string title, int year){
    this->id = id;
    this->title = title;
    this->year = year;
}

Book::Book() {
    id = 0;
    title = "";
    year = 0;
}

Book::~Book() { }

// Get methods
int Book::getId(){
    return this->id;
}

string Book::getTitle(){
    return this->title;
}

int Book::getYear(){
    return this->year;
}

void Book::setId( int id){
    this->id = id;
}

void Book::setName( string title){
    this->title = title;
}

void Book::setYear( int year){
    this->year = year;
}
