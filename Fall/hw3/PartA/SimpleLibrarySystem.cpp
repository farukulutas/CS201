// Ahmet Faruk Ulutas - CS 201-3 - 21803717

#include "SimpleLibrarySystem.h"

LibrarySystem::LibrarySystem() {
    this->studentsHead = NULL;
    this->studentsTail = NULL;
    this->numberOfStudents = 0;
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

void LibrarySystem::deleteStudent(const int studentId) {
    if ( !isStudentExist( studentId) ) {
        cout << "Student " << studentId << " does not exist" << endl;
    }
    else {
        // if first
        if ( this->studentsHead->student.getId() == studentId ) {
            StudentNode * temp = new StudentNode;
            temp = this->studentsHead;
            this->studentsHead = this->studentsHead->next;
            delete temp;
            this->numberOfStudents--;
            cout << "Student " << studentId << " has been deleted" << endl;
            return;
        }

        StudentNode * prevTemp = new StudentNode;
        prevTemp = NULL;

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
            temp = this->studentsTail;
            this->studentsTail = prevTemp;
            this->studentsTail->next = NULL;
        }
        else {
            temp = prevTemp->next;
            prevTemp->next = prevTemp->next->next;
        }

        delete temp;
        delete prevTemp;
        this->numberOfStudents--;
        cout << "Student " << studentId << " has been deleted" << endl;
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
        delete temp;
    }
}
