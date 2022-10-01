#pragma once

#include "api.h"
#include "okapi/api.hpp"

class Claw{
  public:
    Claw(pros::Motor clawMotor);

    void moveClaw(bool qwert, bool aa, bool wer, bool Tog);
  private:
    pros::Motor clawM;
};