#include "Arm.hpp"

Arm::Arm(pros::Motor armMotor) : armM(armMotor){
    
}

void Arm::moveArm(bool toggle, bool otherToggle){
    armM.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    if(toggle && otherToggle == false){
        armM.move_absolute(600, 100);
        otherToggle = true;
    }
    else if(toggle == false && otherToggle == true){
        armM.move_absolute(0, 100);
        otherToggle = false;
    }
}