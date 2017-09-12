//
// Created by Mats Otten on 12/09/2017.
//

#ifndef MOTION_VISION_ROBOT_H
#define MOTION_VISION_ROBOT_H


#include <list>
#include "Arm.h"

class Robot {
private:
    std::list<Arm> arms;
public:
    void addArm(Arm arm);
};


#endif //MOTION_VISION_ROBOT_H
