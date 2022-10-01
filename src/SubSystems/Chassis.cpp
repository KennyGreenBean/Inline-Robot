#include "Chassis.hpp"
#include "pros/motors.hpp"

void Chassis::brake(){
    frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	backRight.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

void Chassis::XDriveTelOp(int leftY, int leftX, int rightX){
    float forward = 1.5748 * leftY;
    float sideways = 1.5748 * leftX;
    float turn = 1.5748 * rightX;

    frontRight.move_velocity(forward - turn - sideways);
    frontLeft.move_velocity(forward + turn + sideways);
    backRight.move_velocity(forward - turn + sideways);
    backLeft.move_velocity(forward + turn - sideways);
}

void Chassis::aimbotMovement(int move){
    if(move == 1){
        frontRight.move_velocity(-30);
        frontLeft.move_velocity(30);
        backRight.move_velocity(-30);
        backLeft.move_velocity(30);
    }
    else if(move == 2){
        frontRight.move_velocity(30);
        frontLeft.move_velocity(-30);
        backRight.move_velocity(30);
        backLeft.move_velocity(-30);
    }
    else if(move == 3){
        frontRight.move_velocity(0);
        frontLeft.move_velocity(0);
        backRight.move_velocity(0);
        backLeft.move_velocity(0);
    } 
}