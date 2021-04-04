#include "SonarUnit.h"

Sonar::Sonar(int inTrig, int inEcho){
	trig = inTrig;
	echo = inEcho;
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	//trig pin must start LOW
	digitalWrite(trig, LOW);
	delay(30);
}

int Sonar::getCM(){
	//Send trig pulse
	digitalWrite(trig, LOW);
	delayMicroseconds(20);
	digitalWrite(trig, HIGH);
	delayMicroseconds(20);
	digitalWrite(trig, LOW);
	long startDelayTime;
	long delayTime;
	long timeOut;

	//Wait for echo start
	startDelayTime = micros();
	while(digitalRead(echo) == LOW){
		delayTime = micros();
		timeOut = (delayTime - startDelayTime)/1000;
		if(timeOut >= 200)
			return 50;
	}

	//Wait for echo end
	long startTime = micros();
	while(digitalRead(echo) == HIGH);
	
	long travelTime = micros() - startTime;

	//Get distance in cm
	int distance = travelTime / 58;

	return distance;
}