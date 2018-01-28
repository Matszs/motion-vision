//
// Created by Mats Otten on 12/09/2017.
// https://www.mathsisfun.com/data/cartesian-coordinates-interactive.html
//

#include "Arm.h"

void Arm::addSegment(Segment segment) {
	Segment *lastSegment = nullptr;
	if(this->segments.size() > 0)
		lastSegment = &segments.back();

    this->segments.push_back(segment);
	(&segments.back())->setMountingSegment(lastSegment);

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

    int loopCounter = 1000;

    while(!this->isNearDestinationPoint() && loopCounter) {

        Segment *lastSegment = &this->segments.back();

		// reversed iterator
		for (std::list<Segment>::reverse_iterator segment(this->segments.rbegin()), iter_end(this->segments.rend()); segment != iter_end; ++segment) {
			segment->rotate(this->destinationPoint, lastSegment);
			this->calculatePoints();
		}

        loopCounter--;
    }
}

void Arm::setThreshold(float value) {
    this->threshold = value;
}

Point Arm::getEndPoint() {
    return Point((&segments.back())->getX(), (&segments.back())->getY());
}

void Arm::calculatePoints() {

    float angleTotal = 0;
    float totalX = 0;
    float totalY = 0;

    for (Segment &segment : segments) {
        angleTotal += segment.getAngle() * M_PI / 180;
        float x = segment.getLength() * cosf(angleTotal);
        float y = segment.getLength() * sinf(angleTotal);

        totalX += x;
        totalY += y;

        segment.setX(totalX);
        segment.setY(totalY);

        cout << "(" << segment.getLabel() << ", " << totalX << ", " << totalY << ")" << ",";
	}
    cout << "\n\n";
}