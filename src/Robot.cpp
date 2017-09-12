//
// Created by Mats Otten on 12/09/2017.
//

#include "Robot.h"

void Robot::addArm(Arm arm) {
    this->arms.push_back(arm);
}

void Robot::setPosition(Point point) {
    this->destinationPoint = point;
}