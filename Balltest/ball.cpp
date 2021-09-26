//
// Created by CJ on 3/4/2021.
//

#include "ball.h"


#include <cmath> //sqrt()



//Calculate distance from this ball to target ball

double Ball::DistanceTo(Ball* targetBall)

{

    long squareDistX = (posX - targetBall->posX) * (posX - targetBall->posX);

    long squareDistY = (posY - targetBall->posY) * (posY - targetBall->posY);

    long squareDistZ = (posZ - targetBall->posZ) * (posZ - targetBall->posZ);

    return sqrt(squareDistX + squareDistY + squareDistZ);

}