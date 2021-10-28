// Charles Brady, cjb5ct, 11/18/2020, 8puzzles.cpp


#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set> 


using namespace std;

void printPuzzle(string puz);
string move(string puz,int direction);
bool findHole(string puz);


//int puzzle[3][3];
string puzzle; 
int hole;

struct node {
  string current;
  vector<node> neighbors;
  int distance;

};


/**
 * @brief Calculates the least amount of moves required to solve an 8 puzzle.
 * 
 * It cycles through all possible moves until it reaches the solution.
 * 
 * @note The puzzle string supplied must contain numbers 0-8 with the
 * 0 representing the hole in the puzzle game
 * @author Charles Brady
 * @date 11/18/2020
 */
int main() {


  //  vector<string> rows;
  
  cout << "Enter puzzle" << endl;

  int i = 0;
  while (i <= 8) {
    string tempNum;
    cin >> tempNum;
    puzzle += tempNum;
    i++;
  }



  

  findHole(puzzle);
  /*
  if (findHole(puzzle)) {
    cout << "Hole Position: " << hole << endl; 
  }
  else {
    cout << "No hole in this puzzle!" << endl; 
  }
  */
  
  node root;
  root.current = puzzle;
  root.distance = 0;


  
  
  for (int i=0;i<=3;i++) {

    string temp = move(root.current,i);
    if (temp != "impossible") {

      node neigh;
      neigh.current = temp;
      neigh.distance = 0;
      
      root.neighbors.push_back(neigh);
    }
  }
 
  // before i use move again, need to refind the hole
  /*
  cout << "These are the root neighbors: " << endl;
  for (string s:root.neighbors) {
    printPuzzle(s);
    cout << endl;
  }
  */
  bool can_solve = false;
  unordered_set<string> searched;
  queue <node> q;
  q.push(root);
  searched.insert(root.current);
  cout << "Solving puzzle" << endl; 
  while (!q.empty()) {
    node v = q.front();
    if (v.current == "123456780") {
      cout << v.distance<< endl;
      // printPuzzle(v.current);
      can_solve = true;
      break;
    }
    //  cout << v.current << " " << v.distance << endl;

    q.pop();

    for (node w:v.neighbors) {
      unordered_set<string>::iterator got = searched.find(w.current);
      if (got == searched.end()) {
	searched.insert(v.current);
	w.distance = v.distance + 1;
	findHole(w.current);
	for (int i=0;i<=3;i++) {
	  string tmp = move(w.current,i);
	  if (tmp != "impossible") {
	    node ne;
	    ne.current = tmp;
	    ne.distance = 0;
	    w.neighbors.push_back(ne);
	  }
	}
        q.push(w);
      }
      
    }
    
  }
  

  if (!can_solve) {
    cout << "IMPOSSIBLE" << endl;
  }
 
    
    
    
  

}


/**
 * @brief Moves the hole of a given puzzle string in the specified direction
 * 
 * 
 * The direction to move the hole is represented by an integer
 * 
 * @param puz A string of numbers representing the puzzle 
 * @param direction An integer represetning the direction to move in
 * 0 is up, 1 is right, 2 is down, 3 is left
 */
string move(string puz,int direction) {
  //  cout<< "Here: " << direction << endl;
  switch (direction)
  {
  case 0:
    if (hole < 3) {
      //    cout << "The Hole can't move up from this position!" << endl;
      return "impossible";
      break;
    }
    swap(puz[hole],puz[hole-3]);
    return puz;
    break;
    
  case 1:
    
    if (hole == 2 || hole == 5 || hole == 8) {
      // cout << "The Hole can't move right from this position!" << endl;
      return "impossible";
      break; 
    }
    swap(puz[hole],puz[hole+1]);
    return puz;
    break;
    
  case 2:
    if (hole > 5) {
      //  cout << "The Hole can't move down from this position!" << endl;
      return "impossible";
      break;
    }
    swap(puz[hole],puz[hole+3]);
    return puz;
    break;
    
  case 3:
   
    
    if (hole == 0||hole==3||hole==6) {
      // cout << "The Hole can't move left from this position!" << endl;
      return "impossible";
      break; 
    }
    swap(puz[hole],puz[hole-1]);
    return puz;
    break;
    

  }
  
  return NULL; 
}


/**
 * @brief Finds the "0" string in a given puzzle configuration which 
 * represents the hole in the game
 * 
 * loops through the given puzzle string and returns the index of the hole
 *
 * @param puz A string of numbers representing the puzzle 
 */
bool findHole(string puz) {
  int i = 0;
  for (char c:puz) {
    if (c == '0') {
      hole = i;
      return true;
    }
    i++;
  }
  return false; 

}


/**
 * @brief Prints a given puzzle string in puzzle format 
 * 
 * Takes in a string of numbers representing the puzzle and formats it to
 * look like the word puzzle game
 *
 * @param puz A string of numbers representing the puzzle 
 */
void printPuzzle(string puz) {
  for (int i=0;i<=8;i++) {
    if (i == 3 || i == 6) {
      cout << endl;
    }
    cout << puz[i] << " ";
  }
  cout << endl; 


}


