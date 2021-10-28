# Charles Brady, cjb5ct, 11/17/2020, Makefile-In-lab 11 

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g
FST=-O2

traveling: traveling.o middleearth.o
	$(CXX) $(DEBUG) $(FST)  traveling.o middleearth.o
	doxygen
	@echo "Ready to semi-solve the Traveling Salesman problem!"

traveling.o: traveling.cpp

middleearth.o: middleearth.h middleearth.cpp


.PHONY: clean
clean:
	-rm -f *.o traveling
