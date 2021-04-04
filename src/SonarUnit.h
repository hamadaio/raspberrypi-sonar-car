#ifndef SONAR_H
#define SONAR_H

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Sonar{
	public:
		Sonar(int inTrig, int inEcho);
		int getCM();
		
	private:
		int trig;
		int echo;
};

#endif