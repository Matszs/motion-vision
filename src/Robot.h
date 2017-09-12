//
// Created by Mats Otten on 12/09/2017.
//

#ifndef MOTION_VISION_ROBOT_H
#define MOTION_VISION_ROBOT_H


#include <list>
#include "Arm.h"
#include "Point.h"

class Robot {
private:
    std::list<Arm> arms;
    Point destinationPoint;
    float threshold;
public:
    void addArm(Arm arm);
    void setDestinationPoint(Point point);
    void setThreshold(float value);
    Point getEndPoint();
    void calculatePoints();
    void run();
    bool isNearDestinationPoint();
};


#endif //MOTION_VISION_ROBOT_H
