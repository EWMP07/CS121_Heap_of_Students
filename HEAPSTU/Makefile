CXX = g++
CXXFLAGS = -Wall -std=c++17

all: program

program: main.o address.o date.o student.o
	$(CXX) $(CXXFLAGS) main.o address.o date.o student.o -o program

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

address.o: address.cpp
	$(CXX) $(CXXFLAGS) -c address.cpp

date.o: date.cpp
	$(CXX) $(CXXFLAGS) -c date.cpp

student.o: student.cpp
	$(CXX) $(CXXFLAGS) -c student.cpp

run: program
	./program

debug:
	$(CXX) -g main.cpp address.cpp date.cpp student.cpp -o program

clean:
	rm -f *.o program

valgrind: program
	valgrind ./program