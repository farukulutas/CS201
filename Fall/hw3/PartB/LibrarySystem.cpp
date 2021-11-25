// Ahmet Faruk Ulutas - CS 201-3 - 21803717

#include "LibrarySystem.h"

LibrarySystem::LibrarySystem() {
    this->studentsHead = NULL;
    this->studentsTail = NULL;
    this->numberOfStudents = 0;
    this->numberOfCheckedBooks = 0;
}

LibrarySystem::~LibrarySystem() { }

void LibrarySystem::addStudent(const int studentId, const string studentName) {
    if ( studentId < 1 ) {
        cout << "Student id must be positive." << endl;
    }
    else if ( isStudentExist( studentId) ) {
        cout << "Student " << studentId << " already exists" << endl;
    }
    else {
        StudentNode *s = new StudentNode;
        s->student.setId( studentId);
        s->student.setName( studentName);

        if ( this->studentsHead == NULL ) {
            this->studentsHead = s;
            this->studentsTail = studentsHead;
        }
        else {
            this->studentsTail->next = s;
            this->studentsTail = this->studentsTail->next;
		}

        this->numberOfStudents++;
        delete s;
        cout << "Student " << studentId << " has been added" << endl;
    }
}

void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear) {
    if ( bookId < 1 ) {
        cout << "Book id must be positive." << endl;
    }
    else if ( isBookExist( bookId) ) {
        cout << "Book " << bookId << " already exists" << endl;
    }
    else if ( isCheckedBookExist( bookId ) ) {
        cout << "Book " << bookId << " already exists and checked" << endl;
    }
    else {
        BookNode *b = new BookNode;
        b->book.setId( bookId);
        b->book.setName( bookName);
        b->book.setYear( bookYear);

        if ( this->booksHead == NULL ) {
            this->booksHead = b;
            this->booksTail = booksHead;
        }
        else {
            this->booksTail->next = b;
            this->booksTail = this->booksTail->next;
		}

        this->numberOfBooks++;
        delete b;
        cout << "Student " << bookId << " has been added" << endl;
    }
}

bool LibrarySystem::isStudentExist( int studentId) const {
    if ( this->studentsHead == NULL ) {
        return false;
    }
    else {
        StudentNode *iter = new StudentNode;
        iter = this->studentsHead;

        do {
            if ( iter->student.getId() == studentId ) {
                delete iter;
                return true;
            }

            iter = iter->next;
        } while ( iter != NULL );

        delete iter;
    }

    return false;
}

bool LibrarySystem::isCheckedBookExist( int bookId) const {
    if ( this->studentsHead == NULL ) {
        return false;
    }
    else {
        StudentNode *iter = new StudentNode;
        iter = this->studentsHead;

        BookNode *bookIter = new BookNode;

        do {
            bookIter = iter->student.booksHead;

            for ( int i = 0; i < iter->student.numberOfBooks; i++) {
                if ( iter->student.booksHead->book.getId() == bookId ) {
                    delete iter;
                    delete bookIter;
                    return true;
                }

                bookIter = bookIter->next;
            }

            iter = iter->next;
        } while ( iter != NULL );

        delete bookIter;
        delete iter;
    }

    return false;
}

bool LibrarySystem::isBookExist( int bookId) const {
    if ( this->booksHead == NULL ) {
        return false;
    }
    else {
        BookNode *iter = new BookNode;
        iter = this->booksHead;

        do {
            if ( iter->book.getId() == bookId ) {
                delete iter;
                return true;
            }

            iter = iter->next;
        } while ( iter != NULL );

        delete iter;
    }

    return false;
}

void LibrarySystem::deleteStudent(const int studentId) {
    if ( !isStudentExist( studentId) ) {
        cout << "Student " << studentId << " does not exist" << endl;
    }
    else {
        // int bookId = -1;

        // if first
        if ( this->studentsHead->student.getId() == studentId ) {
            for ( BookNode *curr = this->studentsHead->student.booksHead; curr != NULL; curr = curr->next ) {
                this->returnBook( curr->book.getId() );
            }

            StudentNode * temp = new StudentNode;
            temp = this->studentsHead;
            this->studentsHead = this->studentsHead->next;
            delete temp;
            this->numberOfStudents--;
            cout << "Student " << studentId << " has been deleted" << endl;
            return;
        }

        StudentNode * prevTemp = NULL;

        // between or tail
        for ( StudentNode *prev = this->studentsHead; prev != NULL; prev = prev->next ) {
            if ( prev->next->student.getId() == studentId ) {
                prevTemp = prev;
                break;
            }
        }

        StudentNode * temp = new StudentNode;
        temp = NULL;

        // if tail
        if ( this->studentsTail->student.getId() == studentId ) {
            for ( BookNode *curr = this->studentsTail->student.booksHead; curr != NULL; curr = curr -> next ) {
                this->returnBook( curr->book.getId() );
            }

            temp = this->studentsTail;
            this->studentsTail = prevTemp;
            this->studentsTail->next = NULL;
        }
        else {
            temp = prevTemp->next;
            for ( BookNode *curren = temp->student.booksHead; curren != NULL; curren = curren -> next ) {
                this->returnBook( curren->book.getId() );
            }

            prevTemp->next = prevTemp->next->next;
        }

        delete temp;
        this->numberOfStudents--;
        cout << "Student " << studentId << " has been deleted" << endl;
    }
}

void LibrarySystem::deleteBook(const int bookId) {
    if ( !isBookExist( bookId) && !isCheckedBookExist( bookId ) ) {
        cout << "Book " << bookId << " does not exists" << endl;
    }
    else {
        if ( isBookExist( bookId) ) {
            // if first
            if ( this->booksHead->book.getId() == bookId ) {
                BookNode *temp = new BookNode;
                temp = this->booksHead;
                this->booksHead = this->booksHead->next;
                delete temp;
                this->numberOfBooks--;
                cout << "Student " << bookId << " has been deleted" << endl;
                return;
            }

            BookNode *prevTemp = new BookNode;
            prevTemp = NULL;

            // between or tail
            for ( BookNode *prev = this->booksHead; prev != NULL; prev = prev->next ) {
                if ( prev->next->book.getId() == bookId ) {
                    prevTemp = prev;
                    break;
                }
            }

            BookNode * temp = new BookNode;
            temp = NULL;

            // if tail
            if ( this->booksTail->book.getId() == bookId ) {
                temp = this->booksTail;
                this->booksTail = prevTemp;
                this->booksTail->next = NULL;
            }
            else {
                temp = prevTemp->next;
                prevTemp->next = prevTemp->next->next;
            }

            delete temp;
            delete prevTemp;
            this->numberOfBooks--;
            cout << "Book " << bookId << " has been deleted" << endl;
        }
        else {
            this->returnBook( bookId);
            this->deleteBook( bookId);
        }
    }
}

void LibrarySystem::checkoutBook(const int bookId, const int studentId) {
    if ( !this->isBookExist( bookId) ) {
        cout << "Book " << bookId << " does not exist" << endl;
    }
    else if ( !this->isStudentExist( studentId) ) {
        cout << "Student " << studentId << " does not exist" << endl;
    }
    else if ( !this->isCheckedBookExist( bookId) ) {
        cout << "Book " << bookId << " has been already checked out by another student" << endl;
    }
    else {
        BookNode *tempBook = new BookNode;
        BookNode *tempBookBook = new BookNode;
        tempBookBook = NULL;
        tempBook = NULL;

        for ( BookNode *curr = this->booksHead; curr != NULL; curr = curr->next) {
            if ( curr->book.getId() == bookId ) {
                tempBook = curr;
                break;
            }
        }

        this->deleteBook( bookId);

        for ( StudentNode *cur = this->studentsHead; cur != NULL; cur = cur->next) {
            if ( cur->student.getId() == studentId ) {
                tempBookBook = cur->student.booksHead;

                for ( int i = 0; i < cur->student.numberOfBooks - 1; i++ ) {
                    tempBookBook = tempBookBook->next;
                }

                tempBookBook->next = tempBook;
                break;
            }
        }

        for ( StudentNode *current = this->studentsHead; current != NULL; current = current->next ) {
            if ( current->student.getId() == studentId ) {
                current->student.numberOfBooks++;
                break;
            }
        }

        delete tempBookBook;
        delete tempBook;
        this->numberOfBooks--;
        this->numberOfCheckedBooks++;
        cout << "Book " << bookId << " has been checked out by student " << studentId << endl;
    }
}

void LibrarySystem::returnBook(const int bookId) {
    if ( !isBookExist( bookId) ) {
        cout << "Book " << bookId << " does not exist" << endl;
    }
    else if ( isCheckedBookExist( bookId) ) {
        cout << "Book " << bookId << " has been already checked out" << endl;
    }
    else {
        BookNode *tempBook = new BookNode;
        StudentNode *tempStudent = new StudentNode;
        tempStudent = NULL;
        tempBook = NULL;

        for ( StudentNode *s = this->studentsHead; s != NULL; s = s->next ) {
            for ( BookNode *b = s->student.booksHead; b != NULL; b = b->next ) {
                tempStudent = s;

                if ( b->book.getId() == bookId ) {
                    tempBook = b;

                    // if first
                    if ( s->student.booksHead->book.getId() == bookId ) {
                        s->student.numberOfBooks--;
                        this->addBook( b->book.getId(), b->book.getTitle(), b->book.getYear() );
                        this->numberOfBooks++;
                        this->numberOfCheckedBooks--;
                        cout << "Book " << bookId << " has been returned" << endl;
                        delete tempBook;
                        delete tempStudent;
                        return;
                    }
                }
                else if ( b->next->book.getId() == bookId ) {
                    tempBook = b->next;

                    // if between or tail
                    if ( tempBook->book.getId() == s->student.booksTail->book.getId() ) {
                        s->student.booksTail = b;
                        s->student.booksTail->next = NULL;
                    }
                    else {
                        // status prev for book
                        b->next = b->next->next;
                    }

                    this->addBook( tempBook->book.getId(), tempBook->book.getTitle(), tempBook->book.getYear() );
                    s->student.numberOfBooks--;
                    this->numberOfBooks++;
                    this->numberOfCheckedBooks--;
                    cout << "Book " << bookId << " has been returned" << endl;
                    delete tempBook;
                    delete tempStudent;
                    return;
                }
            }
        }
    }
}

void LibrarySystem::showAllBooks() const {
    if ( (this->numberOfBooks <= 0) && (this->numberOfCheckedBooks <= 0) ) {
        cout << "There is no book in the library" << endl;
    }
    else {
        cout << "Book id/tBook name/tYear/tStatus" << endl;
        for ( BookNode *curr = this->booksHead; curr != NULL; curr = curr->next ) {
            cout << curr->book.getId() << "/t" << curr->book.getTitle() << "/t" << curr->book.getYear() << "/t" << "Not checked out" << endl;
        }
    }

    if ( this->numberOfCheckedBooks > 0 ) { // check node types and for loop to check every student then print books
        for ( StudentNode *curr = this->studentsHead; curr != NULL; curr = curr->next ) {
            for ( BookNode *current = curr->student.booksHead; current != NULL; current = current->next ) {
                cout << current->book.getId() << "/t" << current->book.getTitle() << "/t" << current->book.getYear() << "/t" << "Checked out by student " << curr->student.getId() << endl;
            }
        }
    }
}

void LibrarySystem::showBook(const int bookId) const {
    if ( this->isBookExist( bookId) ) {
        BookNode *temp = new BookNode;
        temp = this->booksHead;

        do {
            if ( temp->book.getId() == bookId ) {
                cout << temp->book.getId() << "/t" << temp->book.getTitle() << "/t" << temp->book.getYear() << "/t" << "Not checked out" << endl;
                break;
            }

            temp = temp->next;
        } while ( temp != NULL );
    }
    else if ( this->isCheckedBookExist( bookId) ) {
        for ( StudentNode *curr = this->studentsHead; curr != NULL; curr = curr->next ) {
            for ( BookNode *current = curr->student.booksHead; current != NULL; current = current->next ) {
                if ( current->book.getId() == bookId ) {
                    cout << current->book.getId() << "/t" << current->book.getTitle() << "/t" << current->book.getYear() << "/t" << "Checked out by student " << curr->student.getId() << endl;
                    return;
                }
            }
        }
    }
    else {
        cout << "Book does not exist" << endl;
    }
}

void LibrarySystem::showStudent(const int studentId) const {
    if ( !isStudentExist( studentId) ) {
        cout << "Student " << studentId << " does not exist" << endl;
    }
    else {
        StudentNode * temp = new StudentNode;
        temp = this->studentsHead;

        for ( StudentNode *curr = this->studentsHead; curr != NULL; curr = curr->next ) {
            if ( curr->student.getId() == studentId ) {
                temp = curr;
                break;
            }
        }

        cout << "Student id: " << temp->student.getId() << " student name: " << temp->student.getName() << endl;
        cout << "Student " << temp->student.getId() << " has checked out the following books:" << endl;
        cout << "Book id/tBook name/tYear";
        for ( BookNode *iter = temp->student.booksHead; iter != NULL; iter = iter->next ) {
            cout << iter->book.getId() << "/t" << iter->book.getTitle() << "/t" << iter->book.getYear() << endl;
        }

        delete temp;
    }
}
