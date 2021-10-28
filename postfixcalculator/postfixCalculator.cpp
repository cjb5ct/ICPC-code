// Charles Brady, cjb5ct, postfixCalculator.cpp, 9/20/2020
#include "postfixCalculator.h"
#include <iostream>
//#include <stack>
#include <string>
#include "stack.h"

using namespace std;

 

// Methods

inline int postfixCalculator::EvaluateEquation(string equation) {
  
  // stack<int> stack1;
  stack *stack1 = NULL;
  stack1 = new stack();

  for(int i=0;i<equation.length();i++) {
    if(equation[i] == ' ') {
      continue;
    }

    else if(findOperator(equation[i])) {
      if (findNumber(equation[i+1])) {
	  isNegativeNumber = true; 
	}
     
      if (isNegativeNumber) {
      	i++;
	int num = 0; 
	while (i < equation.length() && findNumber(equation[i])) {
	  num = (num * 10) + (equation[i] - '0');
	  i++;
       }
	
	i--;
	num = num * -1;
	//stack1.push(num);
	stack1->push(num);
	isNegativeNumber = false; 
      }
      
      else {
      
	if (equation[i] == '~') {
	  // int element1 = stack1.top();
	  int element1 = stack1->top();
	  // stack1.pop();
	  stack1->pop();
	  int result = element1 * -1;
	  //stack1.push(result);
	  stack1->push(result);
	}
	else {
	
	  //int firstelement = stack1.top();
	  int firstelement = stack1->top();
	  // stack1.pop();
	  stack1->pop();
	  //int secondelement = stack1.top();
	  int secondelement = stack1->top();
	  // stack1.pop();
	  stack1->pop();
	  int final = StepSolver(equation[i], firstelement, secondelement);
	  //stack1.push(final);
	  stack1->push(final);
	}
      }
     

    }
    else if(findNumber(equation[i]) && !isNegativeNumber) {

	int number = 0;
	while (i < equation.length() && findNumber(equation[i])) {
	  number = (number * 10) + (equation[i] - '0');
	  i++;
	}

       	i--;
	//stack1.push(number);
	stack1->push(number);

    }
      
  }

  // return stack1.top();
  return stack1->top();
}

inline int postfixCalculator::StepSolver(char symbol, int element1, int element2) {
  
  if (symbol == '+') {
    return element1 + element2;
  }
  else if (symbol == '-') {
    return element2 - element1;
  }
  else if (symbol == '*') {
    return element1 * element2; 
  }
  else if (symbol == '/') {
    return element2 / element1;
  }


  return 0;
}

inline bool postfixCalculator::findNumber(char element) {
  
  if (element >= '0' && element <= '9') {
    return true;
  }
  return false;

}
      
inline bool postfixCalculator::findOperator(char element) {
 
  if (element == '+' || element == '-'|| element == '*'||
      element == '/' || element == '~') {
    

    return true;
  }
  return false; 
  
}
