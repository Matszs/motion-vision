#include <iostream>
#include "Robot.h"

int main() {
    // units = centimeters

    Robot robot = Robot();
    robot.setThreshold(3);

    robot.addArm(Arm(10, 45)); // lengthangle
    robot.addArm(Arm(10, 10)); // lengthangle

    robot.setDestinationPoint(Point(30, 30)); // x-as & y-as

    robot.run();



    return 0;
}
