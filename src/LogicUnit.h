#ifndef LOGICUNIT_H
#define LOGICUNIT_H

#include "MotorUnit.h"
#include "SonarUnit.h"
#include <vector>
#include <iostream>
#include <wiringPi.h>

class LogicUnit{
	public:
		LogicUnit();  
	
	private:
		void startCar();
		void rangeFinder(int &distanceLeft, int &distanceFront, int &distanceRight);
		void makeMovement();
		void move(int motorOneDir, int motorTwoDir);
		void turnLeft(int inDelay);
		void turnRight(int inDelay);
		void driveForward(int inDelay);
		void driveBackward(int inDelay);
		void stop(int inDelay);
		
		std::vector<Sonar> sonars;
		std::vector<Motor> motors;
		
};

#endif