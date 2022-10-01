#pragma once

#include "api.h"
#include "okapi/api.hpp"
#include "pros/motors.hpp"

class Indexer{
  public:
    Indexer(pros::Motor iMotor);

    void moveIndexer(bool qwerte, bool qwe);
    pros::Motor indexerMotor;
};