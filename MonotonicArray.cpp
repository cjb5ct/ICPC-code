// Write a function that takes in an array of integers and returns a boolean representing whether the array is monotonic 
// An array is said to be monotoinic if its elements, from left to right, are entirely non-increasing or entirely non-decreasing

using namespace std;

bool isMonotonic(vector<int> array) {
  // Write your code here.
	if (array.size() == 0) {
		return true; 
	}
	bool isDec = false; 
	bool isInc = false; 
	int prev = array[0]; 
	for (int i = 1; i < array.size(); i++) {
		if (prev == array[i]) {
			
		}
		else if (prev > array[i]) {
			if (isInc) {
				return false; 
			}
			isDec = true; 
		}
		else if (prev < array[i]) {
			if (isDec) {
				return false; 
			}
			isInc = true; 
		}
		// -1116
		// -2016
		prev = array[i]; 
	}
	return true; 
	/*
	if (isInc && !isDec) {
		return true;
	}
	if (isDec && !isInc) {
		return true; 
	}
	return false; 
  */
}
