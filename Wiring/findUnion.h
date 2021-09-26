//
// Created by CJ on 3/16/2021.
//

#include <iostream>
#include "electric.h"
#include <vector>
#ifndef WIRING_FINDUNION_H
#define WIRING_FINDUNION_H

using namespace std;
class findUnion {
public:
    void makeSet(int i);
    int findSet(int i);
    void unions(int i,int j);
    vector<int> set_var;

private:
};


#endif //WIRING_FINDUNION_H
