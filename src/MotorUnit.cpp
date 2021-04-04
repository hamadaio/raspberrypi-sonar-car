#include "MotorUnit.h"
#include <wiringPi.h>

Motor::Motor(int inEnable, int iNpin1, int iNpin2){
	enable = inEnable;
	pin1 = iNpin1;
	pin2 = iNpin2;
	
	pinMode(enable, OUTPUT);
	pinMode(pin1, OUTPUT);
	pinMode(pin2, OUTPUT);
	setDirection(FORWARD);
}

void Motor::setDirection(int dir){
	if(dir == FORWARD){
		digitalWrite(pin1, HIGH);
		digitalWrite(pin2, LOW);
	} else if(dir == BACKWARD){
		digitalWrite(pin1, LOW);
		digitalWrite(pin2, HIGH);
	}else{
		//...
	}
}

int Motor::getEnable(){
	return enable;
}

int Motor::getPin1(){
	return pin1;
}

int Motor::getPin2(){
	return pin2;
}