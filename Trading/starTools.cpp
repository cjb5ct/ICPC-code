//
// Created by CJ on 3/8/2021.
//

#include "starTools.h"

starTools::starTools() {
}

starTools::~starTools() {}

bool starTools :: CompareStarx (int star1,int star2) {
    //  float star1x = star_cords.at();
    return star_cords[star1][0] > star_cords[star2][0];
}

bool starTools :: CompareStary (float star1, float star2) {
    return star_cords[star1][1] > star_cords[star2][1];
}

bool starTools :: CompareStarz (float star1, float star2) {
    return star_cords[star1][2] > star_cords[star2][2];
}


double starTools :: GetDistance (float star1, float star2) {
    float squaredX = (star_cords[star1][0] - star_cords[star2][0]) * (star_cords[star1][0] - star_cords[star2][0]);
    float squaredY = (star_cords[star1][1] - star_cords[star2][1]) * (star_cords[star1][1] - star_cords[star2][1]);
    float squaredZ = (star_cords[star1][2] - star_cords[star2][2]) * (star_cords[star1][2] - star_cords[star2][2]);

    return sqrt(squaredX + squaredY + squaredZ);
}
/*
float starTools :: minDistSlow (vector<vector<float>> xyz) {

    float minDist;
    for (int i=0; i<star_count - 1; i++) {
        //Check other remaining balls
        for (int j = i + 1; j < star_count; j++)
        {
            float dist = GetDistance(star_cords[i],star_cords[j]);
            // totalDistCalc++;
            if (dist < minDist)
                minDist = dist;
        }

    }

}

*/