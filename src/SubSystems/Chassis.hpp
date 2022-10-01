#pragma once

#include "api.h"
#include "okapi/api.hpp"
#include "pros/motors.hpp"

class Chassis{
  public:
    Chassis(pros::Motor frontLeft, pros::Motor frontRight, pros::Motor backLeft, pros::Motor backRight);

    void brake();
    void XDriveTelOp(int leftY, int leftX, int rightX);
    void aimbotMovement(int move);

    pros::Motor frontLeft;
    pros::Motor frontRight;
    pros::Motor backLeft;
    pros::Motor backRight;
    
};