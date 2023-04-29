CC = gcc
CXX = g++

CFLAGS=-Wall -Werror
CXXFLAGS = -std=c++20 -Wall -Wextra
LDFLAGS = -lm

GTEST_LIB = -lgtest -lgtest_main -pthread

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CFLAGS += -g
    CXXFLAGS += -g
    OUTPUTDIR = bin/debug
else
    CFLAGS += -O3
    CXXFLAGS += -O3
    OUTPUTDIR = bin/release
endif

all: main.exe $(OUTPUTDIR)

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

main.exe: $(OUTPUTDIR)/main.o $(OUTPUTDIR)/calculator.o $(OUTPUTDIR)/shapes.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(OUTPUTDIR)/main.o: main.c calculator.h shapes.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUTDIR)/calculator.o: calculator.c calculator.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUTDIR)/shapes.o: shapes.c shapes.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUTDIR)/shapesTests.o: shapesTests.cpp shapes.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUTPUTDIR)/calculatorTests.o: calculatorTests.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUTPUTDIR)/shapesTests: $(OUTPUTDIR)/shapesTests.o $(OUTPUTDIR)/shapes.o
	$(CXX) -o $@ $^ $(GTEST_LIB) $(LDFLAGS)

$(OUTPUTDIR)/calculatorTests: $(OUTPUTDIR)/calculatorTests.o $(OUTPUTDIR)/calculator.o
	$(CXX) -o $@ $^ $(GTEST_LIB)

test: $(OUTPUTDIR)/shapesTests $(OUTPUTDIR)/calculatorTests
	$(OUTPUTDIR)/shapesTests
	$(OUTPUTDIR)/calculatorTests

clean:
	rm -rf bin
