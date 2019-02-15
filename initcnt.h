#ifndef __INITCNT_H_
#define __INITCNT_H_

#ifdef __ARD
#include "Arduino.h"
#endif

class initcnt
{
	public:
		initcnt();

	public:
		int initNR();
#ifdef __MAKENET__
		int setWeightedNet2NR();
#endif //__MAKENET__
};

#endif //__INITCNT_H_
