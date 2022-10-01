#include "Intake.hpp"
#include "pros/motors.hpp"

Intake::Intake(pros::Motor iMotor) : intakeMotor(iMotor){
  
}

void Intake::moveIntake(bool qwer, bool qwe){
    if(qwer == true){
        intakeMotor.move_velocity(200);
    }
    else if(qwe == true){
        intakeMotor.move_velocity(-200);
    }
    else {
        intakeMotor.move_velocity(0);
    }
}

void Intake::roller(bool color){
    if(color == false){
        intakeMotor.move_velocity(-100);
    }
    else if(color == true){
        intakeMotor.move_velocity(0);
    }
}