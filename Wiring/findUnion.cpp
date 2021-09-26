//
// Created by CJ on 3/16/2021.
//
using namespace std;
#include "findUnion.h"


void findUnion::makeSet(int i) {
    for (int j = 0; j<i; j++) {
        set_var.push_back(j);
    }
}

int findUnion::findSet(int i) {
    // start at index i and repeat
    // to find which set i is in
    while(set_var[i] != i) {
        i = set_var[i];
    }
    return i;

}

void findUnion::unions(int i,int j) {
    int l1 = findSet(i);
    int l2 = findSet(j);
    set_var[l1] = l2;
}