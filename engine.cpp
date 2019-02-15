#include "Arduino.h"
#include "nrinfo.h"
#include "engine.h"

extern char* g_sNRName[];
extern short int g_nNR[__EOM];

engine::engine()
{
}

void engine::InitEngine()
{
	pinMode(LEFT_MOTOR_ENABLE, OUTPUT);
	pinMode(LM_FWD, OUTPUT);
	pinMode(LM_BWD, OUTPUT);

	pinMode(RIGHT_MOTOR_ENABLE, OUTPUT);
	pinMode(RM_FWD, OUTPUT);
	pinMode(RM_BWD, OUTPUT);
}

int engine::fwd(char nP)
{
	right(nP*2);
	left(nP*2);

	return 1;
}

int engine::bwd(char nP)
{
	right(nP*2);
	left(nP*2);

	return 1;
}

//int engine::left(short int nP)
int engine::left(long nP)
{
	if(nP == 0)//stop
	{
		analogWrite(LEFT_MOTOR_ENABLE, 0);
	}
	else if(nP > 0) //fwd
	{
		digitalWrite(LM_FWD, HIGH);
		digitalWrite(LM_BWD, LOW);	
		analogWrite(LEFT_MOTOR_ENABLE, map(nP, 1, 974, 100, 255));
	}
	else if(nP < 0) //bwd
	{
		digitalWrite(LM_FWD, LOW);
		digitalWrite(LM_BWD, HIGH);	
		analogWrite(LEFT_MOTOR_ENABLE, map(nP, -185, -1, 100, 220));
	}
	

	return nP;
}

//int engine::right(short int nP)
int engine::right(long nP)
{
	if(nP == 0)//stop
	{
		analogWrite(RIGHT_MOTOR_ENABLE, 0);
	}
	else if(nP > 0) //fwd
	{
		digitalWrite(RM_FWD, HIGH);
		digitalWrite(RM_BWD, LOW);	
		analogWrite(RIGHT_MOTOR_ENABLE, map(nP, 1, 891, 100, 255));
	}
	else if(nP < 0) //bwd
	{
		digitalWrite(RM_FWD, LOW);
		digitalWrite(RM_BWD, HIGH);	
		analogWrite(RIGHT_MOTOR_ENABLE, map(nP, -166, -1, 100, 220));
	}
	

	return nP;
}


int engine::motor()
{
	short int i; 
	long lsum = 0, rsum = 0;

	for(i = __EON+1; i < __EOM; i++)
	{
                if(i < __LM_EOM) //left
                {
                        if(((i >= __LM_MDL01 && i <= __LM_MDL07) \
                                || (i >= __LM_MVL01 && i <= __LM_MVL07)))
                                continue;
                        lsum += g_nNR[i];
                }
                else if(i >= __LM_EOM) //right
                {
                        if(((i >= __RM_MDR01 && i <= __RM_MDR07) \
                                || (i >= __RM_MVR01 && i <= __RM_MVR07)))
                                continue;
                        rsum += g_nNR[i];
                }
/*
		if(i > __LM_EOM)
		{
			lsum += g_nNR[i];
		}
		else if(i < __LM_EOM)
		{
			rsum += g_nNR[i];
		}
*/

		g_nNR[i] = 0;
	}

	left(lsum);
	right(rsum);

	return 1;
}
