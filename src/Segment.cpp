//
// Created by Mats Otten on 12/09/2017.
//

#include "Segment.h"

Segment::Segment(string label, float length, float angle) {
	this->label = label;
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

string Segment::getLabel() {
	return label;
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

// Reference material; https://github.com/hharrison/vecmath/blob/master/src/javax/vecmath/Vector3d.java
void Segment::rotate(Point destinationEndPoint, Segment *lastSegment) {

	Point target = Point(
			destinationEndPoint.x() - this->getMountingPoint().x(),
			destinationEndPoint.y() - this->getMountingPoint().y(),
			destinationEndPoint.z() - this->getMountingPoint().z()
	);

	Point current = Point(
			lastSegment->getX() - this->getMountingPoint().x(),
			lastSegment->getY() - this->getMountingPoint().y(),
			lastSegment->getZ() - this->getMountingPoint().z()
	);

	target.normalize();
	current.normalize();

	double difference = current.angle(target); // Angle between two, dotProduct, 'inversen cosinus'
	double differenceDegrees = difference * M_PI / 180;

	Point cross = target.cross(current);

	if(differenceDegrees > 6) // simple example damping
		differenceDegrees = 6;

	if(cross.z() > 0) {
		this->setAngle(this->getAngle() - differenceDegrees);
	} else {
		this->setAngle(this->getAngle() + differenceDegrees);
	}
}

Segment * Segment::getMountingSegment() {
	return this->mountingSegment;
}

void Segment::setMountingSegment(Segment * mountingSegment) {
	this->mountingSegment = mountingSegment;
}

Point Segment::getMountingPoint() {
	if(this->mountingSegment != nullptr)
		return Point(this->mountingSegment->getX(), this->mountingSegment->getY(), this->mountingSegment->getZ());
	return Point(); // default Point on 0, 0, 0
}

Point Segment::getEndPoint() {
	return Point(this->getX(), this->getY(), this->getZ());
}

float Segment::getZ() {
	return this->z;
}

void Segment::setZ(float value) {
	this->z = value;
}
