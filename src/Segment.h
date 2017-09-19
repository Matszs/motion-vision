//
// Created by Mats Otten on 12/09/2017.
//

#ifndef MOTION_VISION_SEGMENT_H
#define MOTION_VISION_SEGMENT_H


#include "Point.h"
#include <math.h>

class Segment {
private:
    float length;
    float angle;
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
	Segment* mountingSegment = 0;
public:
    Segment(float length, float angle);
    float getLength();
    float getAngle();
	Segment* getMountingSegment();

    void setLength(float value);
    void setAngle(float value);
	void setMountingSegment(Segment* mountingSegment);

    float getX();
    float getY();
    float getZ();
	Point getMountingPoint();

    void setX(float value);
    void setY(float value);
    void setZ(float value);

	void rotate(Point destinationEndPoint, Segment* lastSegment);
};


#endif //MOTION_VISION_SEGMENT_H
