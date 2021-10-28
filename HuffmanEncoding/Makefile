# Charles Brady, cjb5ct, 11/12/2020, Makefile-Huffman Encoding Post lab 

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

all: encoded decoded

encoded: huffmanenc.o heap.o
	$(CXX) $(DEBUG) -o encoder huffmanenc.o heap.o
	@echo "huffman encoder is ready"

decoded: huffmandec.o 
	$(CXX) $(DEBUG) -o decoder huffmandec.o
	@echo "huffman decoder is ready"

huffmanenc.o: huffmanTNode.h heap.h huffmanenc.cpp

huffmandec.o: huffmanTNode.h huffmandec.cpp

heap.o: heap.h heap.cpp huffmanTNode.h


.PHONY: clean
clean:
	-rm -f *.o encoder decoder
