// Charles Brady, cjb5ct, 10/10/2020, wordPuzzle.cpp


#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <vector>
#include "hashTable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
timer timer1;

bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);
string getDirection(int direction_number);


// arv[0] = a.out argv[1] = dictionary, argv[2] = grid 
int main (int argc, char* argv[]) {

  // MIGHT NEED TO HANDLE INVALID WORDS HERE LATER
  string dictionary_file = argv[1];
  ifstream file(dictionary_file);
  if (!file.is_open()) {
    cout<< "the file did not open!" << endl; 
    return 0; 
  }
  //  unordered_set <string> dictionary;
  // hashTable *Table1 = new hashTable(
  int lines = 0;
  string line; 
  while (getline(file, line)) {
    //  dictionary.insert(line);
    lines++;
  }
  file.close();

  hashTable *dictionary = new hashTable(lines);

  ifstream file1(dictionary_file);
  string line1;
  while (getline(file1, line1)) {
      if (line1.length() > 2) {
	dictionary->insert(line1);
      }
    }
  file1.close();

  string grid_file = argv[2];
  int rows, cols; 
  bool result = readInGrid(grid_file, rows, cols);
    // if there is an error, report it
  if (!result) {
    cout << "Error reading in file!" << endl;
    return 1;
  }
  // cout << endl;


  
  int row_count = 0;
  int column_count = 0;
  int word_count = 0;
  
  int max_word_length;

  if (rows >= 22 || cols >= 22) {
    max_word_length = 22; 
  }
  else if (rows > cols) {
    max_word_length = rows; 
  }
  else if (cols > rows){
    max_word_length = cols; 
  }
  else if (cols == rows) {
    max_word_length = cols;
  }
  string previous;
  timer1.start();

  while (row_count <= rows - 1) {
    if (column_count <= cols - 1) {
      for (int i=0; i < 8; i++) {
	int letter_count = 3;
	previous = "";
	while(letter_count <= max_word_length) {
	  string possible_word = getWordInGrid(row_count,column_count,i,letter_count,rows,cols);
	  // auto search = dictionary.find(possible_word);
	  bool found = dictionary->contains(possible_word);
	  // search != dictionary.end()
	  if (found && possible_word.size() > 2 && possible_word != previous) {
	    cout << getDirection(i) << "(" << row_count << ", " << column_count << "): "  << possible_word << endl;
	    previous = possible_word; 
	    word_count++;
	  }

	  letter_count++;	  
	}
	
      }
      // previous = "";
      column_count++; 
    }
    if (column_count == cols) {
      column_count = 0;
      row_count++; 

    }

  }
  timer1.stop();
  cout << word_count << " words found" << endl;
  double time = timer1.getTime();
  //  cout<< "Found all words in " << time << " seconds" << endl;
  

  
  return 0;

  

}


bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    // cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    // cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
	    // cout << grid[r][c];
        }
	//	cout << endl;
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}


string getDirection(int direction_number) {
  string directions[8] = {"N ","NE","E ","SE","S ","SW","W ","NW"};
  return directions[direction_number]; 

}





 
