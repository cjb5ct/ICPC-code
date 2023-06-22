#include <stack> 
#include <unordered_map>
#include <string>
#include <algorithm> 
using namespace std;

stack<string> s; 
unordered_map<string, bool> visited;

vector<int> get_coord (string s) {
  string y;
  string x; 
  bool first = true;
  for(char c: s){
    if (c == ' '){
      first = false; 
    }
    if (first) {
      y += c; 
    }
    else {
      x += c; 
    } 
  }
  int final_y = stoi(y);
  int final_x = stoi(x);
  vector<int> coords;coords.push_back(final_y);coords.push_back(final_x);
  return coords; 
}

vector<string> get_neighbors(vector<vector<string>> board, int row, int column) {
  vector<string> neighbors; 
  if (row - 1 >= 0) {
    // there's a row above check the top row 
    
    //neighbors.push_back(board[row-1][column]);
    neighbors.push_back(to_string(row-1)+ " " + to_string(column));
    if (column + 1 < board[row-1].size()) {
      // you can look to the right check the right element
     // neighbors.push_back(board[row-1][column+1]); 
      neighbors.push_back(to_string(row-1)+ " " + to_string(column+1));
    }
    if (column - 1 >= 0) {
      // you can look to the left check the left elelment 
      //neighbors.push_back(board[row-1][colulmn-1]);
      neighbors.push_back(to_string(row-1)+ " " + to_string(column-1));
    }
  }
  if (row + 1 < board.size()) {
    // there's a row below check the bottom row 
    
    //neighbors.push_back(board[row+1][column]);
    neighbors.push_back(to_string(row+1)+ " " + to_string(column));
    if (column + 1 < board[row+1].size()) {
      // you can look to the right check the right element
      //neighbors.push_back(board[row+1][column+1]); 
      neighbors.push_back(to_string(row+1)+ " " + to_string(column+1));
    }
    if (column - 1 >= 0) {
      // you can look to the left check the left elelment 
      //neighbors.push_back(board[row+1][colulmn-1]);
      neighbors.push_back(to_string(row+1)+ " " + to_string(column-1));
    }
  }
  if (column + 1 < board[row].size()) {
    // you can look to the right check the right element
    //neighbors.push_back(board[row][column+1]);
    neighbors.push_back(to_string(row)+ " " + to_string(column+1));
  }
  if (column - 1 >= 0) {
    // you can look to the left check the left elelment 
    //neighbors.push_back(board[row][column-1]);
    neighbors.push_back(to_string(row)+ " " + to_string(column-1));
  }
  return neighbors; 
}

vector<vector<string>> dfs (vector<vector<string>> board, int row, int column) {
  string str = to_string(row) + " " + to_string(column);
  stack<string> s;
  s.push(str);
  
  // process the node
  while(!s.empty()) {
    string current = s.top();
    s.pop();
    auto it = visited.find(current); 
    vector<int> current_coord = get_coord(current); 
    string current_letter = board[current_coord[0]][current_coord[1]];
    cout << "Current_coord: " << current << endl; 
    if (it == visited.end()) {
      // the node is not visited so dfs it
      visited.emplace(current, true);

      int mine_count = 0;
      vector<string> neighbors = get_neighbors(board, current_coord[0], current_coord[1]); 
      for (string n : neighbors) {
    
        vector<int> node = get_coord(n);
        string letter = board[node[0]][node[1]];
        if (letter == "M") {
          mine_count += 1;
        }     
      }
      board[current_coord[0]][current_coord[1]] = to_string(mine_count);
      current_letter = to_string(mine_count); 
      for (string n : neighbors) {
        //cout << "Checking neighbors " << n << " "<< current_letter <<endl; 
        vector<int> node = get_coord(n);
        string letter = board[node[0]][node[1]];
        if (letter == "H" && current_letter == "0"){
          cout << "valid neighbor: " << n << endl; 
          s.push(n);
        }
         
      }
    }
  }

  return board; 
}

vector<vector<string>> revealMinesweeper(vector<vector<string>> board, int row,
                                         int column) {
  // Write your code here.
  visited.clear();
  string click = board[row][column]; 
  cout << "clicked : " << click << endl; 
  if (click == "M") {
    // game is lost, just replace the coord with an X
    board[row][column] = "X"; 
  }
  if (click == "H") {
    // first check for the case where this is an adjacent mine, if there is replace the H with how many
    // dfs through the graph (visiting all 0s uintil everything is revealed)
    vector<vector<string>> answer = dfs(board, row, column);
    return answer;
  }
  return board; 
}
