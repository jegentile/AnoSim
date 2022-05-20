/*
 *  AbmState.h
 *  Untitled
 *
 *  Created by James E. Gentile on 1/31/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ABMSTATE_H
#define ABMSTATE_H

#include "AbmSimulation.h"
#include "AbmEnvironment.h"
#include "AbmAgent.h"
#include "AbmStrategy.h"
#include "AbmClasses.h"
#include <string>
using std::string;

class AbmState{
protected:
	
	AbmEnvironment *environment_;
	AbmSimulation* simulation_;
	AbmAgent* agent_;
	
	AbmState** outputs_;
	float* outputThresholds_;
	int numOutputs_;
	int hoursIn_;
	int timeOut_;
	int timeIn_;
	int hourDelay_;
	string name_;
	
public:
	AbmState();
	AbmState(int num_outputs);
	AbmState(int num_outputs, int hoursInState,AbmEnvironment* environment,AbmAgent *agent, string name);
	void setHoursInState(long int hours);
	void setOutput(int index, float threshold, AbmState* toState);
	void setNumberOfOutputs(int numOutputs);
	void setName(string name);
	void setEnvironment(AbmEnvironment* environment);
	AbmEnvironment* getEnvironment();
	string getName();
	int isTimeToLeave();
	~AbmState();
	AbmState* enter();
	virtual AbmState* update();
	//virtual void Print_Info();
};

#endif