// Charles Brady, cjb5ct, stack.cpp, 9/23/2020


#include <iostream>
#include <string>
#include "ListItr.h"
#include "List.h"
#include "stack.h"

using namespace std;



stack::stack() {
  stack_list = new List();
  stack_itr = new ListItr(stack_list->first());
}

stack::~stack() {
  
  if (stack_list != NULL) {
    delete stack_list;
  }
  if (stack_itr != NULL) {
    delete stack_itr;
  }
  
}


void stack::push(int e) {
  stack_list->insertBefore(e, *stack_itr);
  stack_itr = new ListItr(stack_list->first());
}

void stack::pop() {
  if (empty()) {
    throw "pop() attempted on an empty stack";
  }
  stack_list->remove(stack_itr->retrieve());
  stack_itr = new ListItr(stack_list->first());
  
}

int stack::top() {
  if (empty()) {
    throw "top() attempted on an empty stack";
  }
  
  return stack_itr->retrieve();
}

bool stack::empty() {
  return stack_list->isEmpty();
}

/*
int main() {

  stack *stack1 = NULL;
  stack1 = new stack();

  cout<< stack1->empty()<< endl;
  stack1->push(2);
  stack1->push(3);
  stack1->push(4);
  cout<< stack1->empty()<< endl;
  cout<< stack1->top()<< endl;
  stack1->pop();
  cout<< stack1->top()<< endl;
  List *stack_list = NULL;
  ListItr *itr = NULL;
  stack_list = new List();
  itr = new ListItr(stack_list->first());
 
  cout << stack_list->isEmpty()<< endl;
  stack_list->insertAtTail(5);
  stack_list->insertAtTail(6);
  stack_list->insertAtTail(7);

  //  cout << stack_list->first();
  // cout << stack_list->last();
  cout << stack_list->size()<< endl;
  printList(*stack_list, true);
  cout << stack_list->isEmpty() << endl;
  
}
*/