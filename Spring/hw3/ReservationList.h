// Ahmet Faruk Ulutas - CS 201-1 - 21803717

#ifndef ReservationList_h
#define ReservationList_h

class ReservationList {
public:
    ReservationList();
    ReservationList( const ReservationList& aList );
    ~ReservationList();

    bool isEmpty() const;
    int getLength() const ;
    bool retrieve(int index, int& resCode) const;
    bool insert(int index, int resCode);
    bool remove(int index);

private:
    struct ReservationNode{
        int Code;
        ReservationNode* next;
    };
    int size;
    ReservationNode *head;
    ReservationNode *find(int index) const;
    // ...
    //you may define additional member functions and data members, if necessary
};

#endif

