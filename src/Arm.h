//
// Created by Mats Otten on 12/09/2017.
//

#ifndef MOTION_VISION_ARM_H
#define MOTION_VISION_ARM_H


#include "Point.h"
#include <math.h>

class Arm {
private:
    float length;
    float angle;
    float x;
    float y;
public:
    Arm(float length, float angle);
    float getLength();
    float getAngle();

    void setLength(float value);
    void setAngle(float value);

    float getX();
    float getY();

    void setX(float value);
    void setY(float value);
};


#endif //MOTION_VISION_ARM_H
