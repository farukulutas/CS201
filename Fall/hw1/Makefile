#Ahmet Faruk Ulutas - 21803717

all: Homework1

Homework1: main.o ReservationSystem.o Reservation.o Flight.o
	g++ ReservationSystem.o Reservation.o Flight.o -o Homework1

ReservationSystem.o: ReservationSystem.cpp
	g++ -c ReservationSystem.cpp

Reservation.o: Reservation.cpp
	g++ -c Reservation.cpp

Flight.o: Flight.cpp
	g++ -c Flight.cpp

clean:
	rm -rf *o Homework1