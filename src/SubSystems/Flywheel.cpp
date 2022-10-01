#include "Flywheel.hpp"
#include "Indexer.hpp"
#include "pros/optical.h"

Flywheel::Flywheel(okapi::MotorGroup fMotors) : flywheelMotors(fMotors){
  typedef enum motor_gearset_e {
      E_MOTOR_GEARSET_06 // 6:1, 600 RPM, Blue gear set
    } motor_gearset_e_t;
}

float PIDController(float error, float kp, float ki, float kd, float dt)
{
    float integral = 0.0;
    float previousError = 0.0;
	integral = integral + error * dt;
	float derivative = (error - previousError) / dt;
	float output = kp * error + ki * integral + kd * derivative;
	previousError = error;
	return output;
}

void Flywheel::flywheelTelOp(bool up, bool right, bool left, bool down, bool x){
    if(up){
		flywheelMotors.moveVoltage(10000);
	}
	else if(right){
		flywheelMotors.moveVoltage(12000);
	}
	else if (left){
		flywheelMotors.moveVoltage(9700);
	}
	else if (down){
		flywheelMotors.moveVoltage(8700);
	}
	else if (x){
		flywheelMotors.moveVoltage(0);
	}
}