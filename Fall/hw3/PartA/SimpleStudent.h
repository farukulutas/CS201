// Ahmet Faruk Ulutas - CS 201-3 - 21803717

#ifndef SimpleStudent_h
#define SimpleStudent_h

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int id;

public:
    Student( string name, int id);
    Student();
    ~Student();

    int getId();
    string getName();
    void setName( string name);
	void setId( int id);
};

#endif

