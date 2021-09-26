//
// Created by CJ on 3/16/2021.
//
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

#ifndef WIRING_ELECTRIC_H
#define WIRING_ELECTRIC_H
using namespace std;

class electric {
public:
    string type;
    string name;

    vector<unordered_map<electric*,int>> connections;
    unordered_map<string,int> connects_to;

    electric(string nam, string type);
    // ,vector<unordered_map<electric*,int>> cons
    ~electric();

private:
};


#endif //WIRING_ELECTRIC_H
