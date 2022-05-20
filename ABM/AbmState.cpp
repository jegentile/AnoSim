/*
 *  AbmState.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 1/31/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "AbmSimulation.h"
#include "AbmEnvironment.h"
#include "AbmAgent.h"
#include "AbmState.h"


AbmState::AbmState(){
	outputThresholds_= NULL;
	numOutputs_ = 0;
	hoursIn_ = 0;
	timeOut_ = 0;
	hourDelay_ = 0;
	timeIn_ = NULL;

}

AbmState::AbmState(int numOutputs,int hoursInState, AbmEnvironment* environment,AbmAgent* agent, string name){
	numOutputs_ = numOutputs;
	outputThresholds_[numOutputs_];
	environment_ = environment;
	agent_ = agent;
	name_ = name;
	hoursIn_ = hoursInState;
}

AbmState::AbmState(int numOutputs){
	numOutputs_ = numOutputs;
	outputThresholds_[numOutputs_];
	outputs_[numOutputs_];
}
 

AbmState* AbmState::update(){
	return NULL;
}

string AbmState::getName(){
	return name_;
	
}

AbmState::~AbmState(){
	//float* outputThresholds_;
	delete outputs_;
	delete outputThresholds_;
}

void AbmState::setHoursInState(long int hours){
	hoursIn_ = hours;
}

void AbmState::setOutput(int index, float threshold, AbmState* to_state){
	if(index < numOutputs_){
		outputThresholds_[index] = threshold;
		outputs_[index] = to_state;
	}
}
void AbmState::setNumberOfOutputs(int numOutputs){
	numOutputs_ = numOutputs;
	outputs_ = new AbmState*[numOutputs];
	outputThresholds_ = new float[numOutputs];
}

AbmState* AbmState::enter(){
	timeIn_ =environment_->getAbsHour();
	
	return this;
}

int AbmState::isTimeToLeave(){
	if(environment_->getAbsHour()-timeIn_ >= hoursIn_){
		return 1;
	}
	else{ 
		return 0;
	}
}

void AbmState::setName(string name){
	name_ = name;
}

void AbmState::setEnvironment(AbmEnvironment* environment){
	environment_ = environment;
}

AbmEnvironment* AbmState::getEnvironment(){
	return environment_;
}