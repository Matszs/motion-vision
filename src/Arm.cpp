//
// Created by Mats Otten on 12/09/2017.
// https://www.mathsisfun.com/data/cartesian-coordinates-interactive.html
//

#include "Arm.h"

void Arm::addSegment(Segment segment) {
    this->segments.push_back(segment);

    this->calculatePoints();
}

void Arm::setDestinationPoint(Point point) {
    this->destinationPoint = point;
}

bool Arm::isNearDestinationPoint() {
    Point endPoint = this->getEndPoint();
    double distanceBetweenPoints = endPoint.dist(this->destinationPoint);

    return (distanceBetweenPoints < this->threshold);
}

void Arm::run() {

    //while(!this->isNearDestinationPoint()) {

        this->segments.reverse();
        Segment *lastSegment = 0;


        for(Segment& segment : segments) {
            if(lastSegment != 0) {

				

				cout << lastSegment->getAngle() << "\n";

                //float newAngle = (lastSegment->getX() - segment.getX());



            }

            lastSegment = &segment;
        }
        this->segments.reverse();
    //}

}

void Arm::setThreshold(float value) {
    this->threshold = value;
}

Point Arm::getEndPoint() {
    return Point(segments.end()->getX(), segments.end()->getY());
}

void Arm::calculatePoints() {

    float angleTotal = 0;
    float totalX = 0;
    float totalY = 0;

    for (Segment &segment : segments) {
        angleTotal += segment.getAngle() * M_PI / 180;
        float x = segment.getLength() * cosf(angleTotal);
        float y = segment.getLength() * sinf(angleTotal);

        totalX += y;
        totalY += x;

        segment.setX(totalX);
        segment.setY(totalY);

        cout << "(" << totalX << ", " << totalY << ")" << ",";
    }

    cout << "\n\n";

}