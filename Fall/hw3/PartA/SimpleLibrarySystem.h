// Ahmet Faruk Ulutas - CS 201-3 - 21803717

#ifndef LibrarySystem_h
#define LibrarySystem_h

#include <string>
#include "SimpleStudent.h"

using namespace std;

class LibrarySystem {

public:
    LibrarySystem();
    ~LibrarySystem();

    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);

    void showStudent(const int studentId) const;

    bool isStudentExist( const int studentId) const;

private:
    struct StudentNode {
        Student student;
        StudentNode* next = NULL;
    };

    StudentNode* studentsHead;
    StudentNode* studentsTail;
    int numberOfStudents;
};

#endif
