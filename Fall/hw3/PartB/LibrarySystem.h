// Ahmet Faruk Ulutas - CS 201-3 - 21803717

#ifndef LibrarySystem_h
#define LibrarySystem_h

#include <string>
#include "Student.h"
#include "Book.h"

using namespace std;

class LibrarySystem {

public:
    LibrarySystem();
    ~LibrarySystem();

    void addBook(const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);

    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);

    void checkoutBook(const int bookId, const int studentId);
    void returnBook(const int bookId);

    void showAllBooks() const;
    void showBook(const int bookId) const;
    void showStudent(const int studentId) const;

    bool isStudentExist( const int studentId) const;
    bool isBookExist( const int bookId) const;
    bool isCheckedBookExist( const int bookId) const;

private:
    struct StudentNode {
        Student student;
        StudentNode* next = NULL;
    };

    struct BookNode {
        Book book;
        BookNode* next = NULL;
    };

    BookNode* booksHead;
    BookNode* booksTail;
    StudentNode* studentsHead;
    StudentNode* studentsTail;
    int numberOfStudents;
    int numberOfBooks;
    int numberOfCheckedBooks;
};

#endif
