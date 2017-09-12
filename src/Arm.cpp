//
// Created by Mats Otten on 12/09/2017.
//

#include "Arm.h"

Arm::Arm(float length, float angle) {
    this->length = length;
    this->angle = angle;
}

float Arm::getLength() {
    return this->length;
}

float Arm::getAngle() {
    return this->angle;
}

void Arm::setLength(float value) {
    this->length = value;
}

void Arm::setAngle(float value) {
    this->angle = value;
}

float Arm::getX() {
    return this->x;
}

float Arm::getY() {
    return this->y;
}

void Arm::setX(float value) {
    this->x = value;
}

void Arm::setY(float value) {
    this->y = value;
}
