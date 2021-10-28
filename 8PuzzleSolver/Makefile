# Charles Brady, cjb5ct, 11/18/2020, Makefile-Post-lab 11 

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g


8puzzles: 8puzzles.o 
	$(CXX) $(DEBUG)  8puzzles.o
	doxygen
	@echo "Ready to solve some 8puzzles!"

8puzzles.o: 8puzzles.cpp


.PHONY: clean
clean:
	-rm -f *.o 8puzzles
