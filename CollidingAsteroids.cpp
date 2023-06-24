using namespace std;
#include <stack> 
#include <cmath>

/*
Given an array of asteroids with each integer representing the size of the asteroid.
Negative asteroids are moving left and positive asteroids are moving right.
All asteroids are moving at the same speed, so asteroids heading in the same direction can
never collide. 
When two asteroids going opposite directions collide, the bigger asteroid survives and the smaller blows up
(based on absolute value).
If two asteroids are the same size they both blow up. 
Write a function that takes in an array of asteroids and returns the resulting array after all
asteroid collisions occur. 
*/ 

vector<int> collidingAsteroids(vector<int> asteroids) {
  // Write your code here.
  stack<int> asteroids_left; 
  for (int asteroid: asteroids) {
    bool added = true; 
    while (!asteroids_left.empty()) {
      if (asteroid < 0 && asteroids_left.top() > 0) {
        if (abs(asteroid) > abs(asteroids_left.top())) {
          asteroids_left.pop();
        }
        else if (abs(asteroid) < abs(asteroids_left.top())) {
          added = false; 
          break; 
        }
        else if (abs(asteroid) == abs(asteroids_left.top())) {
          asteroids_left.pop();
          added = false; 
          break;
        }
      }
      else {
        break; 
      }
    }
    if (added) asteroids_left.push(asteroid); 
  }
  vector<int> answer; 
  while(!asteroids_left.empty()) {
    answer.insert(answer.begin(), asteroids_left.top());
    asteroids_left.pop(); 
  }
  return answer;
}
