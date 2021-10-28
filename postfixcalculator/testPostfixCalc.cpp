// Charles Brady, cjb5ct, testPostfixCalc.cpp, 9/20/2020

#include <iostream>
//#include <stack>
#include <string>
#include "stack.h"
#include "postfixCalculator.h"
#include "postfixCalculator.cpp"

using namespace std;

int main(){

  postfixCalculator*temp =new  postfixCalculator();
  string postfix;
  // cout << "Postfix Expression: ";
  getline(cin, postfix);
  int final = temp->EvaluateEquation(postfix);
  cout << final << "\n";
  return 0;

}