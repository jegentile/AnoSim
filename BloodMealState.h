/*
 *  BloodMealState.h
 *  Untitled
 *
 *  Created by James E. Gentile on 2/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ABM/AbmState.h"

class BloodMealState: public AbmState{
public:
	BloodMealState();
	BloodMealState(int numOfOutputs,int hoursInState,AbmEnvironment* environment, AbmAgent* agent,string name);
	AbmState* update();
	AbmState* enter();
};