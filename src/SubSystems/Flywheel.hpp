#pragma once

#include "api.h"
#include "okapi/api.hpp"

class Flywheel{
  public:
    Flywheel(okapi::MotorGroup fMotors);
    
    void flywheelTelOp(bool up, bool right, bool left, bool down, bool x);
    float PIDController(float error, float kp, float ki, float kd, float dt);

    okapi::MotorGroup flywheelMotors;
};