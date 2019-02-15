#ifndef __MECHANO_H__
#define __MECHANO_H__

#define trig		12
#define echo		13

class mechano
{
	public:
		mechano();
	public:
		void InitMechano();
		long GetDist();
};

#endif //__MECHANO_H__
