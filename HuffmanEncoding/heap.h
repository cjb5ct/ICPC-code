// Charles Brady, cjb5ct, 11/10/2020, heap.h
// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include "huffmanTNode.h"

using namespace std;

class heap {
public:
    heap();
    heap(vector<huffmanTNode*> vec);
    ~heap();

    void insert(huffmanTNode *x);
    huffmanTNode* findMin();
    huffmanTNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();

private:
    vector<huffmanTNode*> heap1;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
