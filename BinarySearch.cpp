#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
  int l = 0; 
  int r = array.size()-1;
  while (l <= r) {
    int m = (l + r) / 2;
    int middle = array[m];
    if (middle >= target) {
      r = m - 1; 
    }
    else {
      l = m + 1; 
    }
  }
  return (array[l] == target) ? l : -1; 
}
