// Charles Brady, cjb5ct, 11/10/2020, huffmandec.cpp
// read in code taken from inlab-skeleton.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "huffmanTNode.h"
#include <unordered_map>

using namespace std;

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    unordered_map <string, string> preCode;
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
	//  cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
	preCode.insert(make_pair (character,prefix));
	
    }

     
  unordered_map<string, string>:: iterator itr;

  huffmanTNode *root = new huffmanTNode(NULL,NULL);
  
  for (itr = preCode.begin(); itr != preCode.end();itr++) {
    /*
    if (itr->first == " ") {
      cout << "space" << " " << itr->second << endl;
    }
    else {
      cout << itr->first << " " << itr->second << endl;
    }
    */
    huffmanTNode *current = root;
    char character = itr->first[0]; 
    string preC = itr->second;
    while (preC.length() > 1) {
      if (preC[0] == '0') {
	if (current->leftChild == NULL) {
	  current->leftChild = new huffmanTNode(NULL,NULL);
	}
	current = current->leftChild;
	preC = preC.substr(1,preC.length() - 1);
      }
      else if (preC[0] == '1') {
	if (current->rightChild == NULL) {
	  current->rightChild = new huffmanTNode(NULL,NULL);
	}
	current = current->rightChild;
	preC = preC.substr(1,preC.length() - 1); 
      }


    }
    if (preC[0] == '0') {
      current->leftChild = new huffmanTNode(character,NULL);
    }
    else if (preC[0] == '1') {
      current->rightChild = new huffmanTNode(character,NULL);

    }
    

    
  }
  

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
	//	cout<< bits << endl;
	huffmanTNode *itrN = root; 
	for (int i=0;i<= bits.length();i++) {
	  if (bits[i] == '0') {
	    itrN = itrN->leftChild;
	  }
	  else if (bits[i] == '1') {
	    itrN = itrN->rightChild;
	  }
	}
	char decoded = itrN->data;
	cout << decoded; 
        sstm << bits;
    }
    cout << endl;
    //  string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //   cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
}
