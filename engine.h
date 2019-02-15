#ifndef __MOTOR_H__
#define __MOTOR_H__

#ifdef __ARD
#include "Arduino.h"
#endif

#define LEFT_MOTOR_ENABLE       3
#define LM_FWD                  4   
#define LM_BWD                  2   
#define RIGHT_MOTOR_ENABLE      9  
#define RM_FWD                  7   
#define RM_BWD                  8  


class engine
{
	public:
		engine();

	public:
		void InitEngine();
		int motor();
		//int left(short int nP);
		//int right(short int nP);
		int left(long nP);
		int right(long nP);
		int fwd(char nP);
		int bwd(char nP);
};

#endif
