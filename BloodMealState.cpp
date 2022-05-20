/*
 *  BloodMealState.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 2/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "BloodMealState.h"

BloodMealState::BloodMealState(){
	return;
}

BloodMealState::BloodMealState(int numOfOutputs,int hoursInState,AbmEnvironment* environment, AbmAgent* agent, string name){
	numOutputs_ =numOfOutputs;
	outputThresholds_ = new float[numOutputs_];
	outputs_ = new AbmState*[numOutputs_];
	environment_ = environment;
	agent_ = agent;
	name_ = name;
	hoursIn_ = hoursInState;
	return;
}

AbmState* BloodMealState::update(){
	if(isTimeToLeave()){
		return outputs_[0];
	}
	return this;
	
}
AbmState* BloodMealState::enter(){
	return this;
}