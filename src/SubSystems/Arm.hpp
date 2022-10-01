#pragma once

#include "api.h"
#include "okapi/api.hpp"

class Arm{
  public:
    Arm(pros::Motor armMotor);

    void moveArm(bool toggle, bool otherToggle);
  private:
    pros::Motor armM;
};