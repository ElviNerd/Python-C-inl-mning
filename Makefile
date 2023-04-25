CC = gcc
CXX = g++

CFLAGS = -Wall -Wextra -g
CXXFLAGS = -std=c++20 -Wall -Wextra -g
LDFLAGS = -lm

GTEST_LIB = -lgtest -lgtest_main -pthread

all: main

main: main.o calculator.o shapes.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c calculator.h shapes.h
	$(CC) $(CFLAGS) -c $<

calculator.o: calculator.c calculator.h
	$(CC) $(CFLAGS) -c $<

shapes.o: shapes.c shapes.h
	$(CC) $(CFLAGS) -c $<

shapesTests.o: shapesTests.cpp shapes.h
	$(CXX) $(CXXFLAGS) -c $<

calculatorTests.o: calculatorTests.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c $<

shapesTests: shapesTests.o shapes.o
	$(CXX) -o $@ $^ $(GTEST_LIB) $(LDFLAGS)

calculatorTests: calculatorTests.o calculator.o
	$(CXX) -o $@ $^ $(GTEST_LIB)

test: shapesTests calculatorTests
	./shapesTests
	./calculatorTests

clean:
	rm -f *.o main shapesTests calculatorTests
