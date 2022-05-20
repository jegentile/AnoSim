/*
 *  MosquitoStrategy.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 2/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "MosquitoStrategy.h"

MosquitoStrategy::MosquitoStrategy(){
	makeStrategy();
	return;
}



MosquitoStrategy::MosquitoStrategy(AbmEnvironment *environment,AbmAgent* agent){
	agent_ = agent;
	environment_ = environment;
	makeStrategy();
}

void MosquitoStrategy::makeStrategy(){
	
	//cout << "making strat "<< endl << endl;
	
	//Set the number of states
	numOfStates_ = 5;
	allStates_ = new AbmState*[numOfStates_];
	int i=0;
	
	
	emergingState_ = new EmergingState(1,1,environment_,agent_,"Emerging");
	allStates_[i] = emergingState_;
	i++;
	
	
	matingState_ = new MatingState(1,1,environment_,agent_,"Mating");
	allStates_[i] = matingState_;	
	i++;
	
	
	bloodMealState_ = new BloodMealState(1,1,environment_,agent_,"Bloodmeal");
	allStates_[i] = bloodMealState_;
	i++;
	
	
	gravidState_ = new GravidState(1,1,environment_,agent_,"Gravid");
	allStates_[i] = gravidState_;
	i++;
	
	ovipositionState_ = new OvipositionState(1,1,environment_,agent_,"Ovipositing");
	allStates_[i] = ovipositionState_;
	i++;
	
	emergingState_->setOutput(0, 1, matingState_);
	matingState_->setOutput(0, 1, bloodMealState_);
	bloodMealState_->setOutput(0, 1, gravidState_);
	gravidState_->setOutput(0, 1, ovipositionState_);
	ovipositionState_->setOutput(0, 1, matingState_);
	
	//setEnvironment(environment_);
	
	AbmEnvironment* env = emergingState_->getEnvironment();
	
	//cout << "Agent Environment " << env->getName() << " time " << env->getAbsHour() << endl;
	//cout << "Is in : " << env->getParentContainer()->getName() << endl;
	currentState_ = emergingState_->enter();
	
	
	string tmp = environment_->getName();
	
	//cout << "strat is made" << endl;

}