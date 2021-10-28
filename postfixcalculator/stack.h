// Charles Brady, cjb5ct, stack.h, 9/23/2020

#ifndef STACK_H
#define STACK_H



#include <iostream>
#include <string>
#include "List.h"
#include "ListItr.h"

using namespace std;

class stack {

 public:
  stack();
  ~stack();
  void push(int e);
  void pop();
  int top();
  bool empty();
  List *stack_list;
  ListItr *stack_itr;


 private:


};

#endif