#include "Arduino.h"
#include "mechano.h"

/*
#define trig            13
#define echo            12
*/

mechano::mechano()
{
}

void mechano::InitMechano()
{
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
}

long mechano::GetDist()
{
	long duration;

	digitalWrite(trig, LOW);
	delayMicroseconds(2);

	digitalWrite(trig, HIGH);
	delayMicroseconds(10);

	digitalWrite(trig, LOW);

	return (pulseIn(echo, HIGH));
}


