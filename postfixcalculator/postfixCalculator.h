// Charles Brady, cjb5ct, postfixCalculator.h, 9/20/2020
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

class postfixCalculator {

 public:
  int EvaluateEquation(string equation);
  int StepSolver(char symbol, int element1, int element2);
  bool findNumber(char element);
  bool findOperator(char element);
  bool isNegativeNumber = false; 

 private:
  
  
};

#endif
