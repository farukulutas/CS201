// Ahmet Faruk Ulutas - CS 201-3 - 21803717

#ifndef Student_h
#define Student_h

#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

class Student {
private:
    string name;
    int id;

    struct BookNode {
        Book book;
        BookNode* next = NULL;
    };

public:
    Student( string name, int id);
    Student();
    ~Student();

    int getId();
    string getName();
    void setName( string name);
	void setId( int id);

    BookNode *booksHead;
    BookNode *booksTail;
    int numberOfBooks;
};

#endif

