//
// Created by Mats Otten on 12/09/2017.
// https://www.mathsisfun.com/data/cartesian-coordinates-interactive.html
//

#include "Robot.h"

void Robot::addArm(Arm arm) {
    this->arms.push_back(arm);

    this->calculatePoints();
}

void Robot::setDestinationPoint(Point point) {
    this->destinationPoint = point;
}

bool Robot::isNearDestinationPoint() {
    Point endPoint = this->getEndPoint();
    double distanceBetweenPoints = endPoint.dist(this->destinationPoint);

    return (distanceBetweenPoints < this->threshold);
}

void Robot::run() {

    //while(!this->isNearDestinationPoint()) {

        this->arms.reverse();
        Arm *lastArm;


        for(Arm& arm : arms) {
            if(lastArm) {

                //float newAngle = (lastArm->getX() - arm.getX());



            }

            lastArm = &arm;
        }
        this->arms.reverse();
    //}

}

void Robot::setThreshold(float value) {
    this->threshold = value;
}

Point Robot::getEndPoint() {
    return Point(arms.end()->getX(), arms.end()->getY());

    /*float angleTotal = 0;
    float totalX = 0;
    float totalY = 0;

    for(Arm& arm : arms) {
        angleTotal += arm.getAngle() * M_PI / 180;
        float x = arm.getLength() * cosf(angleTotal);
        float y = arm.getLength() * sinf(angleTotal);

        totalX += y;
        totalY += x;
    }

    return Point(totalX, totalY);*/
}

void Robot::calculatePoints() {

    float angleTotal = 0;
    float totalX = 0;
    float totalY = 0;

    for (Arm &arm : arms) {
        angleTotal += arm.getAngle() * M_PI / 180;
        float x = arm.getLength() * cosf(angleTotal);
        float y = arm.getLength() * sinf(angleTotal);

        totalX += y;
        totalY += x;

        arm.setX(totalX);
        arm.setY(totalY);

        cout << "(" << totalX << ", " << totalY << ")" << ",";
    }

    cout << "\n\n";

}