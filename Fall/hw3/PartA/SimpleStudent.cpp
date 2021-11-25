// Ahmet Faruk Ulutas - CS 201-3 - 21803717

#include "SimpleStudent.h"

// default constructor
Student::Student( string name, int id) {
    this->id = id;
    this->name = name;
}

Student::Student() {
    this->id = 0;
    this->name = "";
}

Student::~Student() {}

// getters
int Student::getId(){
    return this->id;
}

string Student::getName(){
    return this->name;
}

void Student::setId( int id) {
	this->id = id;
}

void Student::setName(string name) {
	this->name = name;
}
