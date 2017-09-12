#include <iostream>
#include "Robot.h"

int main() {

    Robot robot = Robot();
    robot.addArm(Arm(10, 30));
    robot.addArm(Arm(10, 30));
    robot.addArm(Arm(10, 30));



    return 0;
}