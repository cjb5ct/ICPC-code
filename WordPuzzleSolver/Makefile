# Charles Brady, cjb5ct, 10/12/2020, Makefile-wordPuzzle

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

wordPuzzle: hashTable.o timer.o wordPuzzle.o
	$(CXX) $(DEBUG)  hashTable.o timer.o wordPuzzle.o
	@echo "wordPuzzle is ready for searching!"

hashTable.o: hashTable.cpp hashTable.h 

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp

.PHONY: clean
clean:
	-rm -f *.o wordPuzzle
