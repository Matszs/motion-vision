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

// Reference material; https://github.com/hharrison/vecmath/blob/master/src/javax/vecmath/Vector3d.java
void Segment::rotate(Point destinationEndPoint, Segment *lastSegment) {

	Point lastSegmentMountPoint = lastSegment->getMountingPoint();

	Point target = Point(destinationEndPoint.x() - lastSegmentMountPoint.x(), destinationEndPoint.y() - lastSegmentMountPoint.y(), destinationEndPoint.z() - lastSegmentMountPoint.z());
	Point current = Point(lastSegment->x - lastSegmentMountPoint.x(), lastSegment->y - lastSegmentMountPoint.y(), lastSegment->z - lastSegmentMountPoint.z());
	Point cross;

	double dotProduct = current.dotProduct(target);
	double difference = current.angle(dotProduct, target); // Angle between two, normalize, dotProduct, 'inversen cosinus'
	double differenceDegrees = difference * M_PI / 180;


	cross = target.cross(current);

	if(cross.z() > 0) {
		this->setAngle(this->getAngle() - differenceDegrees);
	} else {
		this->setAngle(this->getAngle() + differenceDegrees);
	}
}

Segment *Segment::getMountingSegment() {
	return this->mountingSegment;
}

void Segment::setMountingSegment(Segment *mountingSegment) {
	this->mountingSegment = mountingSegment;
}

Point Segment::getMountingPoint() {
	if(this->mountingSegment != 0)
		return Point(this->mountingSegment->getX(), this->mountingSegment->getY(), this->mountingSegment->getZ());
	return Point(); // default Point on 0, 0, 0
}

float Segment::getZ() {
	return this->z;
}

void Segment::setZ(float value) {
	this->z = value;
}
