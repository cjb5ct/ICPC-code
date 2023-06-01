// move all instances of selected integer in place to end of array
#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.
	int count = 0; 
	int size = 0; 
	for (int ele: array) {
		if (ele != toMove) {
			size++; 
		}
	}
	for (int i=0;i<size;i++) {
		if (array[i] == toMove) {
			array.erase(array.begin() + i); 
			i--;
			count++; 
		}
	}
	while (count>0) {
		array.push_back(toMove); 
		count--; 
	}	
  return array;

}
