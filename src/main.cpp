#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor LEFT_MIDDLE(8, pros::E_MOTOR_GEARSET_06, true);
	pros::Motor LEFT_FRONT(7, pros::E_MOTOR_GEARSET_06, true);
	pros::Motor LEFT_BACK(11, pros::E_MOTOR_GEARSET_06, true);
	pros::Motor RIGHT_MIDDLE(16, pros::E_MOTOR_GEARSET_06, false);
	pros::Motor RIGHT_FRONT(9, pros::E_MOTOR_GEARSET_06, false);
	pros::Motor RIGHT_BACK(12, pros::E_MOTOR_GEARSET_06, false);

	pros::Motor Intake(2, pros::E_MOTOR_GEARSET_18, true);

	pros::Motor flywheelMotors(18, pros::E_MOTOR_GEARSET_06, true);

	LEFT_MIDDLE.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	LEFT_FRONT.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	LEFT_BACK.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	RIGHT_MIDDLE.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	RIGHT_FRONT.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
	RIGHT_BACK.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

	while (true) {
		// LeftMotor.spin((Controller1.Axis3.value() + Controller1.Axis1.value()*2));
		// RightMotor.spin((Controller1.Axis3.value() - Controller1.Axis1.value()*2));
		LEFT_MIDDLE.move_velocity((master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)) * 4.7245);
		LEFT_FRONT.move_velocity((master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)) * 4.7245);
		LEFT_BACK.move_velocity((master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) + master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)) * 4.7245);
		RIGHT_MIDDLE.move_velocity((master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)) * 4.7245);
		RIGHT_BACK.move_velocity((master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)) * 4.7245);
		RIGHT_FRONT.move_velocity((master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) - master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X)) * 4.7245);
		
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) == true){
			Intake.move_velocity(200);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == true){
			Intake.move_velocity(-200);
		}
		else{
			Intake.move_velocity(0);
		}

		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
		flywheelMotors.move_voltage(10000);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
			flywheelMotors.move_voltage(12000);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
			flywheelMotors.move_voltage(9700);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
			flywheelMotors.move_voltage(8700);
		}
		else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)){
			flywheelMotors.move_voltage(0);
		}

		std::string temp = std::to_string(Intake.get_temperature());
		pros::lcd::set_text(0, "Intake Temperature: " + temp);
		
		pros::delay(20);
	}
}