#include "Indexer.hpp"
#include "pros/motors.hpp"

Indexer::Indexer(pros::Motor inMotor) : indexerMotor(inMotor){
  
}

void Indexer::moveIndexer(bool qwer, bool qwe){
    if (qwer){
        indexerMotor.move_velocity(200);
    }
    else if(qwer == false && qwe == false){
        indexerMotor.move_voltage(0);
    }
    else if(qwe){
    indexerMotor.move_velocity(-200);
    }
}