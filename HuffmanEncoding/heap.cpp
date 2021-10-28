// Charles Brady, cjb5ct, 11/10/2020, heap.cpp
// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
using namespace std;

// default constructor

heap::heap() : heap_size(0) {
  huffmanTNode *temp = new huffmanTNode(0,0);
  heap1.push_back(temp);
}
/*
heap::heap() {
  heap_size = 0;
  huffmanTree *temp = new huffmanTree('z',0);
  heap1.push_back(temp);
}
*/

// builds a heap from an unsorted vector
heap::heap(vector<huffmanTNode*> vec) : heap_size(vec.size()) {
    heap1 = vec;
    heap1.push_back(heap1[0]);
    heap1[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanTNode *x) {
    // a vector push_back will resize as necessary
    heap1.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}


void heap::percolateUp(int hole) {
    // get the value just inserted
    huffmanTNode *x = heap1[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->freq < (heap1[hole/2]->freq)); hole /= 2) {
        heap1[hole] = heap1[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heap1[hole] = x;
}

huffmanTNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffmanTNode *ret = heap1[1];
    // move the last inserted position into the root
    heap1[1] = heap1[heap_size--];
    // make sure the vector knows that there is one less element
    heap1.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffmanTNode *x = heap1[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && ((heap1[child+1]->freq) < (heap1[child]->freq))) {
            child++;
        }
        // if the child is greater than the node...
	if (x->freq > (heap1[child])->freq) {
            heap1[hole] = heap1[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    heap1[hole] = x;
}

huffmanTNode* heap::findMin () {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return heap1[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    heap1.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << heap1[0] << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << heap1[i]->data << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}



/*
int main() {
  heap h;
  
  h.insert(new huffmanTree('b',1));
  h.insert(new huffmanTree('c',1));
  h.insert(new huffmanTree('d',2));
  h.insert(new huffmanTree('a',3));

  // cout << h.findMin() << endl;
  cout << h.size() << endl;
  h.print();
  cout << h.deleteMin() << endl; 
  cout << h.size() << endl; 
  // cout << h.isEmpty() << endl;
  
  h.print();
  h.makeEmpty();
  cout << h.isEmpty() << endl; 


// dbacaad

  



}
*/
