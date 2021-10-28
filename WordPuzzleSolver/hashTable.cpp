// Charles Brady, cjb5ct, 10/12/2020, hashTable.cpp


#include "hashTable.h"

hashTable::hashTable(int size) {
    buckets = new vector<list<string>>;
    size = size << 1;
    if (!checkprime(size))
        size = getNextPrime(size);    
    buckets->resize(size);
    finalSize = size;                       
    for (int i = 0; i < size; i++)
    {
        list<string> temp;
        buckets->push_back(temp);
    }

}

hashTable::~hashTable() {
    delete buckets;
}

bool hashTable::contains(const string &word) const {
    list<string> & list1 = buckets->at(hashFunc(word));
    bool containCheck = (find(list1.begin(),list1.end(),word) != (list1.end()));
    return containCheck;
}

bool hashTable::insert(const string &word) {
    if (!(this->contains(word)))
    {
        list<string> & list1 = buckets->at(hashFunc(word));
        list1.push_back(word);
        return true;
    }
    return false;
}

int hashTable::hashFunc(const string &word) const {
  
    int hash1 = 1;
    int len = word.length();
    for ( int i = 0; i < len; i ++)
    {
        hash1 *= (((word[i])*thirtySeven(i)) % 136);
        hash1 = hash1 << 1;
    }
    hash1 %= finalSize;
    if (hash1 < 0) {
      return hash1 + finalSize;
    }
    else {
      return hash1;
    }

}


bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

int hashTable::thirtySeven (int n) const {
  int array1[22];
  array1[0] = 37;
  for (int i=1; i <= 22; i++) {
    array1[i] = array1[i-1] * 37;
  }
  // cout<< array1[1] << endl; 
  return array1[n];
  


}

/*
int main() {
  

  
  hashTable *Table = new hashTable(1000);

  // cout<< Table->thirtySeven(3) << endl; 
  cout<< Table->insert("hello") << endl;
  cout<< Table->insert("goodbye")<< endl;
  cout<< Table->contains("goodbye")<< endl;
  cout<< Table->contains("hello")<< endl;
  




  return 0;
}
*/
