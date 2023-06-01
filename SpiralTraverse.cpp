/* Write a function that takes in an n x m two-dimensional array and returns a on-dimensional array
and returns a one-dimensional array of all the array's elements in spiral order 
*/
using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
  // Write your code here.
	int leftbound = 0;
	int rightbound = array[0].size()-1;
	int topbound = 0;
	int bottombound = array.size()-1;
	int counter = 0; 
	int size = array.size() * array[0].size();
	bool up, right, down, left = false;
	right = true; 
	vector<int> answer;
	if (array.size() <= 1) {
		for(int ele:array[0]) {
			answer.push_back(ele);
		}
		return answer;
	}
	if (array.size() > 1 && array[0].size()==1) {
		for (int i = 0;i<=bottombound; i++) {
			answer.push_back(array[i][0]);
		}
		return answer;
 	}
	cout << "size " << size << endl; 
	while(counter <= size) {
		if (right) {
			for (int i= leftbound; i<=rightbound;i++) {
				answer.push_back(array[topbound][i]);
				counter++;
				
				cout << array[topbound][i] << endl; 
			}
			right = false;
			down = true; 
			topbound += 1; 
		}
		if (down) {
			for (int i = topbound; i<=bottombound;i++) {
				answer.push_back(array[i][rightbound]);
				counter++;
				
				cout << array[i][rightbound] << endl; 
			}
			down = false; 
			left = true; 
			rightbound -= 1; 
			
		}
		if (left) {
			for (int i = rightbound;i >= leftbound; i--) {
				answer.push_back(array[bottombound][i]);
				counter++;
				
				cout << array[bottombound][i] << endl; 
			}
			left = false;
			up = true;
			bottombound -= 1;
			
		}
		if (up) {
			for (int i = bottombound; i>=topbound; i--) {
				answer.push_back(array[i][leftbound]);
				counter++;
				//cout << "i " << i << endl; 
				cout << array[i][leftbound] << endl; 
			}
			up = false;
			right = true;
			leftbound += 1; 
			
		}
		//cout << "counter "<< counter << endl; 
		
		counter++;
	}
	/*
	for (int ele: answer) {
		cout << ele << endl; 
	}*/
	if (answer.size() > size) {
		answer.pop_back();
	}
  return answer;
}
