#pragma once

#include "api.h"
#include "okapi/api.hpp"
#include "pros/motors.hpp"

class Intake{
  public:
    Intake(pros::Motor iMotor);

    void moveIntake(bool qwerte, bool qwe);
    void roller(bool color);

    pros::Motor intakeMotor;
};