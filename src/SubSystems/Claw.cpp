#include "Claw.hpp"

Claw::Claw(pros::Motor clawMotor) : clawM(clawMotor){
    
}

void Claw::moveClaw(bool qwert, bool aa, bool wer, bool Tog){
    if(qwert == true && aa == false){
    clawM.move_velocity(100);
    }
    else if (qwert == false && aa == false){
        clawM.move_velocity(0);
    }
    else if (wer == true && aa == false){
        aa = true;
    }
    else if (wer == true && aa == true){
        aa = false;
    }
    else if (qwert == true && aa == true && Tog == false){
        clawM.move_absolute(600, 100);
        Tog = true;
    }
    else if (qwert == true && aa == true && Tog == true){
        clawM.move_absolute(0, 100);
        Tog = false;
    }
}