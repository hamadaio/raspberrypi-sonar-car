#include "LogicUnit.h"

#define FORWARD 	1
#define BACKWARD 	0
#define TURNDELAY 	50
#define VALID 	50
#define RANGEUPPERLIMIT 300
#define RANGELOWERLIMIT 10
#define TURN180 1500

LogicUnit::LogicUnit(){
	wiringPiSetup();
	startCar();
}

void LogicUnit::startCar(){
	//skapa sonar och bil objekt

	sonars.push_back(Sonar(7, 6));//trig echo
	sonars.push_back(Sonar(2, 3));//trig echo
	sonars.push_back(Sonar(4, 5));//trig echo
	
	motors.push_back(Motor(23, 22, 21));	
	motors.push_back(Motor(26, 27, 25));
	
	while(1){
		makeMovement();
	}
}

void LogicUnit::makeMovement(){
	int distanceLeft = 0;
	int distanceFront = 0;
	int distanceRight = 0;
	rangeFinder(distanceLeft, distanceFront, distanceRight);
	
	if(distanceFront < 15){
		stop(1000);
		exit(1);
	}else if(distanceFront < 30)
		turnLeft(TURN180);
	/*else if(distanceRight > VALID && distanceRight > distanceFront && distanceRight >= distanceLeft)
		turnRight(TURNDELAY);
	else if(distanceLeft > VALID && distanceLeft > distanceFront && distanceLeft >= distanceRight)
		turnLeft(TURNDELAY);*/
	else if(distanceLeft <= distanceRight && distanceLeft < VALID)
		turnRight(TURNDELAY);
	else if(distanceRight <= distanceLeft && distanceRight < VALID)
		turnLeft(TURNDELAY);
	else
		driveForward(TURNDELAY);
}

void LogicUnit::rangeFinder(int &distanceLeft, int &distanceFront, int &distanceRight){
	
	 distanceLeft = sonars[0].getCM();
	 distanceLeft =(distanceLeft > RANGEUPPERLIMIT)? RANGEUPPERLIMIT : distanceLeft;
	 distanceLeft =(distanceLeft < RANGELOWERLIMIT)? RANGELOWERLIMIT : distanceLeft;
	 
	 distanceFront = sonars[1].getCM();
	 distanceFront =(distanceFront > RANGEUPPERLIMIT)? RANGEUPPERLIMIT : distanceFront;
	 distanceFront =(distanceFront < RANGELOWERLIMIT)? RANGELOWERLIMIT : distanceFront;
	 
	 distanceRight = sonars[2].getCM();
	 distanceRight =(distanceRight > RANGEUPPERLIMIT)? RANGEUPPERLIMIT : distanceRight;
	 distanceRight =(distanceRight < RANGELOWERLIMIT)? RANGELOWERLIMIT : distanceRight;
}

void LogicUnit::move(int motorOneDir, int motorTwoDir){
	motors[0].setDirection(motorOneDir);
	motors[1].setDirection(motorTwoDir);
	digitalWrite(motors[0].getEnable(), HIGH);
	digitalWrite(motors[1].getEnable(), HIGH);
}

void LogicUnit::turnLeft(int inDelay){
	//std::cout << "LEFT " << inDelay << std::endl;
	move(BACKWARD, FORWARD);
	delay(inDelay);
}

void LogicUnit::turnRight(int inDelay){
	//std::cout << "RIGHT " << inDelay << std::endl;
	move(FORWARD, BACKWARD);
	delay(inDelay);
}

void LogicUnit::driveForward(int inDelay){
	//std::cout << "FORWARD " << inDelay << std::endl;
	move(FORWARD, FORWARD);
	delay(inDelay);
}

void LogicUnit::driveBackward(int inDelay){
	//std::cout << "BACKWARD " << inDelay << std::endl;
	move(BACKWARD, BACKWARD);
	delay(inDelay);
}

void LogicUnit::stop(int inDelay){
	std::cout << "STOP " << inDelay << std::endl;
	digitalWrite(motors[0].getEnable(), LOW);
	digitalWrite(motors[1].getEnable(), LOW);
	delay(inDelay);
}