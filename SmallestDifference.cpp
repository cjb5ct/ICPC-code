/* Write a function that takes in two non-empty arrays of integers, find the pair of numbers whose
absolute difference is closest to zero 
*/

#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
	sort(arrayOne.begin(),arrayOne.end()); 
	sort(arrayTwo.begin(),arrayTwo.end()); 
	int absDiff = 9999999; 
	vector<int> answers; 
	
	for (int i=0;i<arrayOne.size();i++) {
		for (int j=0;j<arrayTwo.size();j++) {
			
			if(arrayOne[i] <= arrayTwo[j]) {
				// if the first one is less than the second then subtract the first from the second 
				int temp = arrayTwo[j] - arrayOne[i]; 
				if (temp < absDiff) {
					absDiff = temp; 
					answers.clear();
					answers.push_back(arrayOne[i]);
					answers.push_back(arrayTwo[j]);
				}
			}
			
			else {
				// if the first one is greater than the second than subtract the second from the first
				
				int temp = arrayOne[i] - arrayTwo[j]; 
				if (temp < absDiff) {
					absDiff = temp; 
					answers.clear();
					answers.push_back(arrayOne[i]);
					answers.push_back(arrayTwo[j]);
					
				}
			}
			
			
		}
	}
  return answers;
}