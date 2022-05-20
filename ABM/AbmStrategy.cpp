/*
 *  AbmStrategy.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 1/31/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#include "AbmStrategy.h"

AbmStrategy::AbmStrategy(){
	environment_ = NULL;
	agent_ = NULL;
	currentState_ = NULL;
}

AbmStrategy::AbmStrategy( AbmEnvironment* environment, AbmAgent* agent){
	environment_ = environment;
	agent_= agent;
	this->makeStrategy();
}

void AbmStrategy::setEnvironment(AbmEnvironment* environment){
	environment_ = environment_;
	for (int i=0;i<numOfStates_; ++i) {
		if(allStates_[i]){
			allStates_[i]->setEnvironment(environment_);
		}
	}
}


void AbmStrategy::update(){
	cout << currentState_->getName() << endl;
	currentState_= currentState_->update() ;
}

void AbmStrategy::makeStrategy(){
	return;
}

void AbmStrategy::printCurrentState(){
	cout<< currentState_->getName() << endl;
}

AbmStrategy::~AbmStrategy(){
	int count = numOfStates_;
	for (int i=0; i<count; i++){
		delete allStates_[i];
	}

}
