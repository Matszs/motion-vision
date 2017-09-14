//
// Created by Mats Otten on 12/09/2017.
//

#ifndef MOTION_VISION_ARM_H
#define MOTION_VISION_ARM_H


#include <list>
#include "Segment.h"
#include "Point.h"

class Arm {
private:
    std::list<Segment> segments;
    Point destinationPoint;
    float threshold;
public:
    void addSegment(Segment segment);
    void setDestinationPoint(Point point);
    void setThreshold(float value);
    Point getEndPoint();
    void calculatePoints();
    void run();
    bool isNearDestinationPoint();
};


#endif //MOTION_VISION_ARM_H
