# use g++ with C++11 support
CXX=g++
CXXFLAGS=-Wall -pedantic -g -O0 -std=c++11
OUTFILES=MatrixTest

all: $(OUTFILES)

MatrixTest: MatrixTest.cpp Matrix.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -o MatrixTest MatrixTest.cpp Matrix.cpp

clean:
	$(RM) $(OUTFILES) *.o