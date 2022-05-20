/*
 *  Pond.h
 *  Untitled
 *
 *  Created by James E. Gentile on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef POND_H
#define POND_H

#include "ABM/AbmEnvironment.h"

class Pond: public AbmEnvironment{
public:
	Pond();
	void clearInbox();
	double getRoomForEggs();
	void applyDeathRate();
};


#endif