#include "LogicUnit.h"
#include <iostream>
#include <sys/time.h>

int main(){
	std::cout << "STARTING... " << std::endl;
	LogicUnit car = LogicUnit();

	/*struct timeval tp;
	long int ms, i = 0; 
	while(i<100){
		gettimeofday(&tp, NULL);
		ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
		std::cout << "..MS.." << ms << std::endl;
		i++;
	}*/
	return 0;
}