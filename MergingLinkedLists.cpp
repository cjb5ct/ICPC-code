using namespace std;
#include <unordered_map> 
// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) {
    this->value = value;
  }
};

unordered_map<int, int> listHolder; 
void mergeHelper(LinkedList* linkedlist) {
  // if (linkedlist->value) {
  //   cout << linkedlist->value << endl; 
    
  // }
  if (linkedlist->next) {
    listHolder.emplace(linkedlist->value, linkedlist->next->value);
    mergeHelper(linkedlist->next);
  }
  else{
    listHolder.emplace(linkedlist->value, NULL); 
  }
}

LinkedList* potential = NULL; 
 
LinkedList* checkSecond(LinkedList* linkedlist) {
  // if (linkedlist->value) {
  //   cout << linkedlist->value << endl; 
    
  // }
  // if (linkedlist->value == 0) {
  //   cout << linkedlist->value << endl; 
  // }
  if (linkedlist->next) {
    //cout << linkedlist->value << endl; 
    // if this happens then we have a potential link 
    if(listHolder[linkedlist->value] == linkedlist->next->value && listHolder[linkedlist->value] != NULL) {
      if(potential == NULL) {
       // cout << "potential found: " << linkedlist->value << endl; 
        potential = linkedlist; 
      }
    }
    checkSecond(linkedlist->next); 
  }
  else if (potential == NULL) {
    auto it = listHolder.find(linkedlist->value);
    if (it != listHolder.end()) {
      potential = linkedlist; 
    }
    return potential; 
  }
  return potential;
   
}

LinkedList* mergingLinkedLists(LinkedList* linkedListOne, LinkedList* linkedListTwo) {
  // Write your code here.
  listHolder.clear();
  potential = NULL; 
  //cout << "one" << endl; 
  mergeHelper(linkedListOne);
  //cout << "two" << endl; 
  //mergeHelper(linkedListTwo);
  return checkSecond(linkedListTwo);
}

