#ifndef __DENDRITE_H__
#define __DENDRITE_H__

#ifdef __ARD
#include "Arduino.h"
#endif

class dendrite
{
	public:
		dendrite();
	public:
		int firenr(const unsigned short int nr);
		int acum(unsigned short int nr);
};

#endif //__DENDRITE_H__
