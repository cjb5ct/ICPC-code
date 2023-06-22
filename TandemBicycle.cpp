/*
A tandem bycyle that's operated by two people: person A and person B. Both people pedal
the bicycle but the person that pedals faster dictates the speed ofthe bicycle. So if person A pedals at
a speed of 5, and person B pedals at a speed of 4, the tandem bicycle moves at a speed of 5 (i.e.,
tandemSpeed = max(speedA, speedB)). 
You're given two lists of positive integers: one that contains the speeds of riders wearing red shits and 
one that contains the speeds of riders wearing blue shirts. Each rider is represented by a single positive
integer, which is the speed that they pedal a tandem bicycle at. HBoth lists have the same length, 
meaning that there are as many red-shirt riders as there are blue-shirt riders. Your goal is to pair every
rider wearing a red shirt with a rider weraring a blue shirt to operate a tandem bicycle. 
Write a function that returns the maximum possible total speed or the minimum possible total speed 
of all the tandem bicycles being ridden based on an input parameter, fastest. If 
fastest = true, your function should return the maximum possible total speed; otherwise it
should return the minimum total speed. 

"Total Speed" is defined as the sum of the speeds of all the tandem bicycles being ridden. For example, 
if there are 4 riders (2 red-shirt riders and 2 blue-shirt riders) who have speeds of 1, 3, 4, 5, and if 
they're paired on tandem bicycles as follows: [1,4], [5,3], then the total speed of these 
tandem bicycles is 4+5 = 9.

sample Input 
redShirtSpeeds = [5, 5, 3, 9, 2[
blueShirtSpeeds = [3, 6, 7, 2, 1]
fastest = true

sample output 
32
*/


#include <vector>
#include <algorithm> 
using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest) {
  // Write your code here.
	
	sort(redShirtSpeeds.begin(),redShirtSpeeds.end());
	sort(blueShirtSpeeds.begin(),blueShirtSpeeds.end()); 
  

	cout << "red riders: " << endl; 
	for (int n:redShirtSpeeds) {
		cout <<  n << endl; 
	}
	cout << "blue riders: " << endl; 
	for (int n:blueShirtSpeeds) {
		cout << n << endl; 
	}
	int total_speed = 0; 
	int bluecounter = 0; 
	if (fastest) {
		for (int i=redShirtSpeeds.size()-1;i>=0;i--) {
			if (redShirtSpeeds[i] >= blueShirtSpeeds[bluecounter]) {
				
				total_speed += redShirtSpeeds[i]; 
			}
			else {

				total_speed += blueShirtSpeeds[bluecounter]; 
			}
			
			bluecounter++; 
		}
	}
	else {
		int redcounter = blueShirtSpeeds.size()-1; 
		for (int i=redShirtSpeeds.size()-1;i>=0;i--) {
			if (redShirtSpeeds[i] >= blueShirtSpeeds[redcounter]) {
				cout << "Selected red: "<< redShirtSpeeds[i] << endl; 
				total_speed += redShirtSpeeds[i]; 
			}
			else {
				cout << "Selected blue: "<< blueShirtSpeeds[redcounter] << endl;
				total_speed += blueShirtSpeeds[redcounter]; 
			}
			
			redcounter--; 
		}
	}
	
	return total_speed;

}
