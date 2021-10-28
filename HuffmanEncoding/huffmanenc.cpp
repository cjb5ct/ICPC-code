// Charles Brady, cjb5ct, 11/7/2020, huffmanenc.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
//#include "huffmanTree.h"
#include "heap.h" 

using namespace std;

huffmanTNode* merge(huffmanTNode *tree1, huffmanTNode *tree2) {
  huffmanTNode *ret = new huffmanTNode(NULL,NULL);
  ret->freq = tree1->freq + tree2->freq;

  ret->leftChild = tree1;
  ret->rightChild = tree2;

  return ret; 
}

unordered_map <char, string> preCode;

void printR(huffmanTNode *n, string preC) {
  if (n->leftChild == NULL && n->rightChild == NULL) {


    if (n->data == ' ') {
      cout << "space " << preC << endl;
      preCode.insert(pair<char,string> (n->data, preC));
    }
    else {
 
      cout << n->data << " " << preC << endl;
      preCode.insert(pair<char,string> (n->data, preC));	
    }  
  }
  if (n->leftChild != NULL) {
    printR(n->leftChild, preC + "0");
  }
  if (n->rightChild != NULL) {
    printR(n->rightChild, preC + "1");
  }

}

int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "File name not supplied as the only paremeter" << endl;
    exit(1);
  }

  ifstream file(argv[1]);
  if (!file.is_open()) {
    cout << "Unable to open '" << argv[1] << "' for reading" << endl;
    exit(2);

  }
  // 
  char temp;
  unordered_map <char, int> charFreq;
  while (file.get(temp)) {
    //  cout << temp;
    if (temp >= ' ' && temp <= '~') {
      if (charFreq.find(temp) == charFreq.end()) {
	charFreq.insert(make_pair(temp, 1));
      }
      else {
	charFreq[temp]+= 1;
      }

    }
   
  }


  heap h;
  
  unordered_map<char, int>:: iterator itr;
  // cout<< "This is the found characters and their Frequencies: " << endl;
  int x = 0;
  for (itr = charFreq.begin(); itr != charFreq.end();itr++) {
    /*
    if (itr->first == ' ') {
      cout << "space" << " " << itr->second << endl;
    }
    else {
      cout << itr->first << " " << itr->second << endl;
    }
    */
    
    x+= itr->second;
    h.insert(new huffmanTNode(itr->first,itr->second));
    
  }
  //  cout << "Characters Detected: " << x << endl; 
  // cout<< "Size of Heap after Node Insertion: " << h.size() << endl;

  //  cout << "Heap Representation: " << endl; 
  //  h.print();
  huffmanTNode *tempt1, *tempt2, *ftree;

  while (h.size() > 1) {
    
    tempt1 = h.deleteMin();
    tempt2 = h.deleteMin();
    
    // cout << tempt1->amount << endl;
    // cout << tempt2->amount << endl; 
    // ftree = merge(tempt1,tempt2);
    huffmanTNode *ret = new huffmanTNode(NULL,NULL);
    ret->freq = tempt1->freq + tempt2->freq;
    ret->leftChild = tempt1;
    ret->rightChild = tempt2;
    
    h.insert(ret);

  }
  
  ftree = h.deleteMin();
  //  cout<< "This should be equal to the number of chars: " << ftree->freq << endl; 
  printR(ftree, "");

  cout << "----------------------------------------" << endl;

  file.clear();
  file.seekg(0);

  char temp3;
  int compressedBits = 0;
  while (file.get(temp3)) {
    
    //  uncompressedBits++;
    if (preCode.find(temp3) == preCode.end()) {
	
      }
      else {
	
	cout << preCode[temp3] << " ";
	compressedBits += preCode[temp3].length();
      }
    /*
    if (temp3 >= ' ' && temp3 <= '~') {
      cout<< preCode.find(temp3)->second << " ";

    }
    */
  }
  
  cout << endl; 
  file.close();
  cout << "----------------------------------------" << endl;

  // uncompressedBits*=8;
  int uncompressedBits = x*8;

  double compr = ((double)uncompressedBits)/compressedBits;
  
  double cost = ((double)compressedBits)/(uncompressedBits/8);
  
  // dbacaad
  cout<< "There are a total of " << x << " symbols that are encoded." << endl;
  cout << "There are "<< charFreq.size()<< " distinct symbols used." << endl;
  cout<< "There were "<<uncompressedBits<<" bits in the original file."<<endl;
  cout<< "There were "<<compressedBits<<" bits in the compressed file."<<endl;
  cout<< "This gives a compression ratio of " << compr <<"." << endl;
  cout<< "The cost of the Huffman tree is "<<cost<<" bits per character."<<endl;
}
// normal 4 missing apostrophe

// double U i normal 2 




