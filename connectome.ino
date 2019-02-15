#include "nrinfo.h"
#include "initcnt.h"
#include "dendrite.h"
#include "engine.h"
#include "mechano.h"



unsigned int ffeed = 0;

initcnt cnt;
dendrite dend;
engine motor;
mechano mecha;

extern short int g_nNR[__EOM];


void setup() 
{
	//setup motor
	motor.InitEngine();

	//init Mechano();
	mecha.InitMechano();

        //debug
        //pinMode(13, OUTPUT);

	//bluetooth
	//Serial.begin(9600);
  
        //init nr
	cnt.initNR();

}

void loop() 
{
	unsigned int i;
	int nDist = 0;

	//measuring dist
	nDist = (int)(mecha.GetDist() / 29 / 2); //make to cm.

	if(nDist < 10 && nDist > 0)
	{
		//motor.left(0);
		//motor.right(0);

		dend.firenr(__ASHL);
		dend.firenr(__ASHR);
		dend.firenr(__FLPL);
		dend.firenr(__FLPR);
		dend.firenr(__IL1VL);
		dend.firenr(__IL1VR);
		dend.firenr(__OLQDL);
		dend.firenr(__OLQDR);
		dend.firenr(__OLQVL);
		dend.firenr(__OLQVR);

		//run!
		for(i = 0; i < __EON; i++)
		{
			if(g_nNR[i] > WTHRESHOLD)
			{
				dend.firenr(i);
				g_nNR[i] = 0;
			}
		}
		motor.motor();
		delay(300);
	}
	else //get feed
	{
		if(ffeed < 4)
		{
			dend.firenr(__ADFL);
			dend.firenr(__ADFR);
			dend.firenr(__ASGR);
			dend.firenr(__ASGL);
			dend.firenr(__ASIL);
			dend.firenr(__ASIR);
			dend.firenr(__ASJR);
			dend.firenr(__ASJL);
			dend.firenr(__AWCL);
			dend.firenr(__AWCR);
			dend.firenr(__AWAL);
			dend.firenr(__AWAR);

			//run!
			for(i = 0; i < __EON; i++)
			{
				if(g_nNR[i] > WTHRESHOLD)
				{
					dend.firenr(i);
					g_nNR[i] = 0;
				}
			}

			motor.motor();
			delay(500);
		}

		ffeed += 1;
		if(ffeed > 40)
		{
			ffeed = 0;
		}
	}
	
  
	//digitalWrite(13, HIGH);
  
	//motor.motor();


	//digitalWrite(13, LOW);
	//delay(10);
}


