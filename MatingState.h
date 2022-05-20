/*
 *  MatingState.h
 *  Untitled
 *
 *  Created by James E. Gentile on 2/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ABM/AbmState.h"

class MatingState: public AbmState{
public:
	MatingState();
	MatingState(int numOfOutputs,int hoursInState,AbmEnvironment* environment, AbmAgent* agent,string name);
	AbmState* update();
	AbmState* enter();
};