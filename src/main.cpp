#include <iostream>
#include "Arm.h"

int main() {
    Arm arm = Arm();
    arm.setThreshold(1);

    arm.addSegment(Segment("arm 1", 10, 45)); // label, length, angle
    arm.addSegment(Segment("arm 2", 10, 10)); // label, length, angle
    arm.addSegment(Segment("arm 3", 10, 20)); // label, length, angle

    arm.setDestinationPoint(Point(18, 22)); // x-as & y-as

    arm.run();

	Point endPoint = arm.getEndPoint();

	cout << "Endpoint: " << endPoint.x() << ", " << endPoint.y() << endl;

    return 0;
}
