# Charles Brady, cjb5ct, 11/15/2020, Makefile-Pre-lab 11 

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

topological: topological.o
	$(CXX) $(DEBUG)  topological.o
	doxygen
	@echo "Topological Sort is ready for sorting"

topological.o: topological.cpp


.PHONY: clean
clean:
	-rm -f *.o topological
