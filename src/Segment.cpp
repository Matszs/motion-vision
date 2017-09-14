//
// Created by Mats Otten on 12/09/2017.
//

#include "Segment.h"

Segment::Segment(float length, float angle) {
    this->length = length;
    this->angle = angle;
}

float Segment::getLength() {
    return this->length;
}

float Segment::getAngle() {
    return this->angle;
}

void Segment::setLength(float value) {
    this->length = value;
}

void Segment::setAngle(float value) {
    this->angle = value;
}

float Segment::getX() {
    return this->x;
}

float Segment::getY() {
    return this->y;
}

void Segment::setX(float value) {
    this->x = value;
}

void Segment::setY(float value) {
    this->y = value;
}
