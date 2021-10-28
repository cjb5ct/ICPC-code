// Charles Brady, cjb5ct, 11/14/2020, topological.cpp 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <deque>
#include <bits/stdc++.h>


using namespace std;


/**
 * @brief Computes the Topological Sort of a supplied graph
 *
 * This main function computes the topological sort of a graph  using the supplied
 * file with a series of directed edges
 * @author Charles Brady
 * @return void
 * @param argc The number of command line arguments being passed in (should be one) 
 * @param argv The commandline parameters themselves
 * 
 * @attention {This code does not contain any helper methods, therefore I wasn't sure how much to doxy.}
 * @note This code contains commented out sections which are made to print out
 * the various data structures involved in the process, uncomment them to see
 * more of the process
 */

//  * @details Main declares the maps and typedefinitions to be used in the sort, 
// * reads the input file and stores the results in the structures.

// * @var <unordered_map> <vertex_map>
// * Contains a list of the vertices in the graph and the vertices which they point to

int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // could use var 

    unordered_map<string,vector<string>> vertex_map;
    vector <string> edges; 
    typedef pair <string, vector<string>> vertex;
    unordered_map<string,int> vert_list;
    typedef pair <string,int> vertex1;
    
    // read in two strings
    string s1, s2;
    while (s1 != "0" && s2 != "0") {
      file >> s1;
      file >> s2;
      if (s1 == "0") {
	break;
      }
      unordered_map <string, vector<string>>::iterator itr = vertex_map.find(s1);
      unordered_map <string, vector<string>>::iterator itr1 = vertex_map.find(s2);
      
      if (itr == vertex_map.end()) {
	// if the first vertex is not in the vertex list add it 
	vertex_map.insert(vertex(s1,edges));
	vertex_map[s1].push_back(s2); 
      }
      else {
	// the first vertex is in the vertex list
	vertex_map[s1].push_back(s2);
      }
      if (itr1 == vertex_map.end()) {
	// if the second vertex is not in the vertex list add it
	vertex_map.insert(vertex(s2,edges));
	// add the connecting edge for the second element into vertex map 
	//	vertex_map[s2].push_back(s1); 
      }
      else {
	//	vertex_map[s2].push_back(s1);
	
      }
      
      
      unordered_map <string, int>::iterator itra = vert_list.find(s1);
      unordered_map <string, int>::iterator itrb = vert_list.find(s2);
      if (itra == vert_list.end()) {
	// if the first vertex is not in the vertex list add it 
	vert_list.insert(vertex1(s1,0));
      }
      else {
	// the first vertex is in the vertex list, do nothing 
      }
      if (itrb == vert_list.end()) {
	// if the second vertex is not in the vertex list add it
	// initialize it with weight of 1 b/c vertex going into it 
	vert_list.insert(vertex1(s2,1));
	
      }
      else {
	// the second vertex is in the vertex list,add 1 to weight
	// b/c there is a vertex going into it
	vert_list[s2] += 1; 
      }
      
      
      

    }
    /*
    unordered_map<string, int>:: iterator itrt;
    cout<< "This is the found vertices and their indegrees: " << endl;
    for (itrt = vert_list.begin(); itrt != vert_list.end();itrt++) {
      cout << itrt->first << " ";
      cout << itrt->second<<endl; 
    
    }
    cout << endl;
    */
    /*
    unordered_map<string, vector<string>>:: iterator itr;
    cout<< "This is the found vertices and their edges: " << endl;
    for (itr = vertex_map.begin(); itr != vertex_map.end();itr++) {
      cout << itr->first<< ": ";
      sort(itr->second.begin(),itr->second.end());
      for (string s:itr->second) {
	cout<< s << " ";
      }
      cout << endl; 
    
    }
    */
    
    deque <string> q;

    unordered_map<string, vector<string>>:: iterator itrz;
    for (itrz = vertex_map.begin(); itrz != vertex_map.end();itrz++) {
      if (vert_list[itrz->first] == 0) {      
	q.push_front(itrz->first);

      } 
    }
    int counter = 0;
    while (!q.empty()) {
      sort(q.begin(),q.end());
      string v = q.front();
      q.pop_front();
      cout << v << " ";
      counter++;
      for (string w:vertex_map[v]) {
	if (vert_list[w] - 1 == 0) {
	  vert_list[w] -=1;
	  q.push_front(w);
	}
	vert_list[w]-=1;

      }

    }
    
    if (counter != vertex_map.size()) {
      cout << endl; 
      cout << "Cycle found, invalid Graph for Topological Sort" << endl;
      exit(3);
    }
    cout << endl;
    
    

    // close the file before exiting
    file.close();
}
