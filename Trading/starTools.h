//
// Created by CJ on 3/8/2021.
//


#ifndef TRADING_STARTOOLS_H
#define TRADING_STARTOOLS_H

#include <vector>
#include <cmath>

class starTools {




public:
    starTools();
    ~starTools();


    // Global Variables
    int star_count;
    vector<vector<float>> star_cords;


    bool CompareStarx (int star1,int star2);
    bool CompareStary (float star1, float star2);
    bool CompareStarz (float star1, float star2);
    double GetDistance (float star1, float star2);
 //   float minDistSlow (vector<vector<float> cords> xyz);
};


#endif //TRADING_STARTOOLS_H
