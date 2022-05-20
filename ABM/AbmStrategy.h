/*
 *  AbmStrategy.h
 *  Untitled
 *
 *  Created by James E. Gentile on 1/29/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef ABMSTRATEGY_H
#define ABMSTRATEGY_H

#include "AbmSimulation.h"
#include "AbmEnvironment.h"
#include "AbmAgent.h"
#include "AbmState.h"
#include "AbmClasses.h"

class AbmState;

class AbmStrategy {
protected:
	
	AbmEnvironment *environment_;
	AbmAgent *agent_;
	
	AbmState **allStates_;
	AbmState *currentState_;
	int numOfStates_;
	
public:
	AbmStrategy();
	AbmStrategy(AbmEnvironment* environment, AbmAgent* agent);
	void update();
	void printCurrentState();
	void makeStrategy();
	void setEnvironment(AbmEnvironment* environment);
	~AbmStrategy();
};

#endif
