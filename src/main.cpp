#include <iostream>
#include "Arm.h"

int main() {
    // units = centimeters

    Arm arm = Arm();
    arm.setThreshold(3);

    arm.addSegment(Segment("arm 1", 10, 45)); // label, length, angle
    arm.addSegment(Segment("arm 2", 10, 10)); // label, length, angle
    arm.addSegment(Segment("arm 3", 10, 20)); // label, length, angle

    arm.setDestinationPoint(Point(20, 20)); // x-as & y-as

    arm.run();



    return 0;
}
