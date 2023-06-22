using namespace std;
// 1 2 3 2 2 1 2 
int majorityElement(vector<int> array) {
  // Write your code here.

  cout << endl; 
  int length = array.size(); 
  int guess = array[0];
  int instances = 1; 
  //cout << length / 2 << endl; 
  for(int i = 1; i < array.size(); i++) {
    //cout << array[i] << endl;
    if (guess == array[i]) {
      instances += 1; 
    }
    else { 
      instances -= 1; 
    }
    if (instances >= length / 2 + 1) {
      // has to be the majority 
      return guess; 
    }
    if (instances <= -1) {
      guess = array[i];
      instances = 1; 
    }

    
    //cout << "Guess: " << guess << " Instances: " << instances << endl; 
  }
  return guess;
  
}
