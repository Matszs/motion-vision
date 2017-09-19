#include <iostream>
#include "Arm.h"

int main() {
    // units = centimeters

    Arm arm = Arm();
    arm.setThreshold(3);

    arm.addSegment(Segment(10, 45)); // lengthangle
    arm.addSegment(Segment(10, 10)); // lengthangle
    arm.addSegment(Segment(10, 20)); // lengthangle

    arm.setDestinationPoint(Point(20, 20)); // x-as & y-as

    arm.run();



    return 0;
}
