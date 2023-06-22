#include <vector>
#include <unordered_map> 
#include <stack> 
using namespace std;
unordered_map<string, bool> search_list;
vector<vector<string>> potentials; 

vector<int> get_coords (string coord) {
  string x = "";
  string y = ""; 
  bool passed = false;
  for (int i = 0 ; i < coord.size();  i++) {
    if (coord[i] == ' ' && !passed){
      // you've found the break so skip 
      passed = true; 
    }
    else if (passed) {
      x += coord[i];
    }
    else {
      // you haven't passed so keep adding to y 
      y += coord[i]; 
    }
    
  }
  //cout << "x: " << x << " y: " << y << endl; 
  int xcoord = stoi(x);
  int ycoord = stoi(y); 
  vector<int> to_num;
  to_num.push_back(ycoord);
  to_num.push_back(xcoord);
  return to_num; 
}


vector<string> get_adjacent (vector<vector<int>> matrix, string coord) {
  vector<string> answer;
  // check up first
  vector<int> to_num = get_coords(coord); 
  int xcoord = to_num[1];
  int ycoord = to_num[0]; 
  if (ycoord - 1 >= 0 && matrix[ycoord-1][xcoord] != 0) {
    string new_coord = to_string(ycoord - 1) + " " + to_string(xcoord);
    answer.push_back(new_coord);
  }
  // check right 
  if (xcoord + 1  < matrix[ycoord].size() && matrix[ycoord][xcoord+1] != 0) {
    string new_coord = to_string(ycoord) + " " + to_string(xcoord + 1);
    answer.push_back(new_coord);
  }
  // check down
  if (ycoord + 1 < matrix.size() && matrix[ycoord+1][xcoord] != 0) {
    string new_coord = to_string(ycoord + 1) + " " + to_string(xcoord);
    answer.push_back(new_coord);
  }
  // check left
  if (xcoord - 1 >= 0 && matrix[ycoord][xcoord-1] != 0) {
    string new_coord = to_string(ycoord) + " " + to_string(xcoord - 1);
    answer.push_back(new_coord);
  }
  return answer;
}

void dfsRemove(vector<vector<int>> matrix, string coord) {
  vector<string> island_list; 
  stack<string> s; 
  s.push(coord);
  bool island = true; 
  while (!s.empty()){
    string current = s.top(); 
    s.pop();
    auto it = search_list.find(current);
    if (it == search_list.end()) {
      // the element isnt discovered so 
      //cout << current << endl; 
      search_list.emplace(current, true);
      island_list.push_back(current); 
      vector<string> adj_list = get_adjacent(matrix, current);
      for(string node: adj_list){
        s.push(node); 
      }
    }
  }
  potentials.push_back(island_list); 
}


vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
    search_list.clear();
    potentials.clear(); 
    if(matrix.size()<=2) {
      return matrix; 
    }
  // Write your code here.

  // loop through the matrix once and dfs each island found adding it to the mapped list
  for (int row = 0; row < matrix.size(); row++) {
    // row
    for(int col = 0; col < matrix[row].size(); col++) {
      //cout << "row: " << row << " col: " << col << endl; 
      string coord = to_string(row) + " " + to_string(col);

      if (matrix[row][col] != 0 ){
        // its equal to 1 and not on the edge of the island and it hasn't been searched so we need to check 
        
        // dfs 
        //cout << coord << endl; 
        dfsRemove(matrix, coord);
      }
    }
    
  }

  for (vector<string> pot: potentials) {
    bool is_island = true; 
    for (string ele: pot) {
      //cout << ele << ", ";
      vector<int> coords = get_coords(ele);
      if (coords[0] == 0|| coords[0] == matrix.size()-1|| coords[1] == 0 || coords[1] == matrix[coords[0]].size()-1) {
        // if a piece of the island is on the edge then it cant be added
        is_island = false; 
      }
    }
    if (is_island) {
      for (string ele: pot){
        vector<int> coords = get_coords(ele);
        //cout << coords[0] << " " << coords[1] << ", ";
        matrix[coords[0]][coords[1]] = 0; 
      }
      
    }
  }

  return matrix; 
}
