#ifndef MOTOR_H
#define MOTOR_H

#define FORWARD 	1
#define BACKWARD 	0

class Motor{
	public:
		Motor(int inEnable, int iNpin1, int iNpin2);
		void dCom(int speed);
		void setDirection(int dir);
		int getEnable();
		int getPin1();
		int getPin2();
	
	private:
		int enable;
		int pin1;
		int pin2;
	
};

#endif