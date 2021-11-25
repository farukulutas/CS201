// Ahmet Faruk Ulutas - CS 201-1 - 21803717
#include <iostream>
#include <string>

using namespace std;

#include "ReservationList.h"

ReservationList::ReservationList(): size(0), head(NULL) {

}

ReservationList::ReservationList( const ReservationList& aList ) {
    if ( aList.head == NULL )
        head = NULL;
    else {
        head = new ReservationNode;
        head->Code = aList.head->Code;

        ReservationNode *newPtr = head;

        for ( ReservationNode *origPtr = aList.head->next; origPtr != NULL; origPtr = origPtr->next ) {
            newPtr->next = new ReservationNode;
            newPtr = newPtr->next;
            newPtr->Code = origPtr->Code;
        }
        newPtr->next = NULL;
    }
}

ReservationList::~ReservationList() {
    while ( !isEmpty() )
        remove(1);
}

bool ReservationList::isEmpty() const {
    return size == 0;
}

int ReservationList::getLength() const {
    return size;
}

bool ReservationList::retrieve(int index, int& resCode) const {
    if ((index < 1) || (index > getLength()))
        return false;

    ReservationNode *cur = find(index);
    resCode = cur->Code;

    return true;
}

bool ReservationList::insert(int index, int resCode) {
    int newLength = getLength() + 1;

    if ((index < 1) || (index > newLength))
        return false;

    ReservationNode *newPtr = new ReservationNode;
    size = newLength;
    newPtr->Code = resCode;

    if ( index == 1) {
        newPtr->next = head;
        head = newPtr;
    }
    else {
        ReservationNode *prev = find(index-1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;

}

bool ReservationList::remove(int index) {
    ReservationNode *cur;

    if ((index < 1) || (index > getLength() ))
        return false;

    --size;
    if (index == 1) {
        cur = head;
        head = head->next;
    }
    else {
        ReservationNode *prev = find(index-1);
        cur = prev->next;
        prev->next = cur->next;
    }

    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;
}

ReservationList::ReservationNode *ReservationList::find(int index) const {
    if ( (index < 1) || (index > getLength()) )
        return NULL;

    else {
        ReservationNode *cur = head;
        for ( int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }
}
