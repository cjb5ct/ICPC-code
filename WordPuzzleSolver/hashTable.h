// Charles Brady, cjb5ct 10/12/2020, hashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class hashTable {
    public:
        hashTable(int size);
        ~hashTable();
        bool contains(const string &word) const;
        bool insert(const string &word);
        int finalSize;

    private:
        vector<list<string>> *buckets;
        int hashFunc(const string &word) const;
        int getNextPrime (unsigned int n);
        bool checkprime (unsigned int p);
	int thirtySeven (int n) const;
	
};

#endif
