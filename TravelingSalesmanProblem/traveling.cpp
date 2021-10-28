// Charles Brady, cjb5ct, 11/16/2020, traveling.cpp
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

/**
 * @brief Calculates the shortest route possible to stop at every city in a given list
 * of cities.
 * It cycles through each possible route and stores the shortest ones until it finds
 * the shortest route.
 *
 * @author Charles Brady
 * @date 11/17/2020
 */
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    // MiddleEarth& med = me;
    
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    
    /*
    cout << "Itinerary printed: " << endl; 
    for (string ct:dests) {
      cout << ct << endl; 
    }
    */
    
    
    string begin = dests.at(0);
   


    //  string start_temp = dests.front();
    // dests.erase(dests.begin());
    
    sort(dests.begin(),dests.end());
    //  string begin = dests.at(0);
    
    float shortest = 1000000;
    float temp_dist;
 //   string found;
    vector<string> almost_route;
    do {
      // begin = dests.at(0);
      temp_dist = computeDistance(me,begin,dests);
      //  temp_dist += med.getDistance(*dests.end(),start_temp);
      // temp_dist += med.getDistance(start_temp,*dests.begin());
      if (temp_dist < shortest) {
	shortest = temp_dist;
	//	cout << shortest << endl;
	almost_route = dests;
      }
      
    } while (next_permutation(dests.begin()+1,dests.end()));
    // cout << computeDistance(me,begin, dests) << endl;
    
    // dests = almost_route;
    //  auto it = almost_route.begin();
    // almost_route.insert(it,start_temp);
    //  begin = almost_route.at(0);
    
    // almost_route.push_back(start_temp);
    // begin = almost_route.at(almost_route.size()-1);
    cout << "Minimum path has distance " << computeDistance(me,begin,almost_route) << ": ";
    printRoute(begin,almost_route);
    
    return 0;
}


/**
 * @brief Computes the full distance of the cycle that starts at the 'start' parameter
 * 
 * It goes to each of the cities in the list of destinations IN ORDER
 * It ends back at the 'start' parameter
 *
 * @return float representing the total distance between all the cities 
 * @param me Reference to the MiddleEarth object which helps in computing distance
 * @param start A string representing the city which to start computing the distance from
 * @param dests A vector of strings representing the cities to travel to
 * 
 */
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  auto iter = find(dests.begin(),dests.end(),start);
  int i;
  if (iter != dests.end()) {
    i = iter - dests.begin();
  }
  string previous;
  float overall = 0; 
  while (iter != dests.end() - 1) {
    // cout << *iter

    previous = *iter;
    iter++;
    float between = me.getDistance(previous,*iter);
    overall += between;
    
    //   cout << "distance between " << previous << " and " << *iter << ": " << between << endl; 
    
  }
  
  previous = *iter;
  iter = dests.begin();
  float btwn = me.getDistance(previous,*iter);
  overall += btwn;
  // cout << "distance between " << previous << " and " << *iter << ": " << btwn << endl;
  
  while (*iter != start) {
    previous = *iter;
    iter++;
    float between = me.getDistance(previous,*iter);
    overall += between; 
    // cout << "distance between " << previous << " and " << *iter << ": " << between << endl;
  }
  
  return overall; 
}

/**
 * @brief Prints the entire route, starting and ending at the 'start' parameter
 *
 * The output should be similar to
 * Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
 *
 * @return void 
 * @param start a string representation of the city which to start the route at
 * @param dests a vector of strings representing the route to be printed 
 * 
 * 
 */

void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  
  auto iter = find(dests.begin(),dests.end(),start);

  int i;
  if (iter != dests.end()) {
    i = iter - dests.begin();
  }
  //  cout << i << endl;
  while (iter != dests.end()) {
    cout << *iter << " -> ";
    iter++;
  }
  iter = dests.begin();
  while (*iter != start) {
    cout << *iter << " -> ";
    iter++;
  }
  cout << start << endl;  
  
  
  
}

