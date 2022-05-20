/*
 *  AbmAgentList.cpp
 *  
 *
 *  Created by Gregory Davis on 1/31/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "AbmAgentList.h"

#include <iostream>
#include "AbmEnvironment.h"
#include "AbmAgent.h"
#include "AbmSimulation.h"
#include "AbmClasses.h"

	
	// Constructors

/*
AbmAgentList::AbmAgentList(){
	agents_ = new AbmAgent*[ABMAGENTLIST_SIZE];
	
	for (long int i=0; i<ABMAGENTLIST_SIZE; ++i) {
		agents_[i] = NULL;
	}
	
	environment_ = NULL;
	
	size_= ABMAGENTLIST_SIZE;
	count_ = 0;
	indexToEnd_= 0;
	
}

AbmAgentList::AbmAgentList( AbmEnvironment *environment){
	environment_ = environment;
}	

AbmAgentList::AbmAgentList(int numOfInitialAgents,AbmEnvironment* environment){
	environment_ = environment;
	count_= 0;
	size_ = numOfInitialAgents;
	agents_ = new AbmAgent*[numOfInitialAgents];
	
	 for(long int i = 0; i < numOfInitialAgents; ++i){
		 agents_[i] = NULL;
	}
	 
	
}
	
/*
void AbmAgentList::update(){
	for(long int i=0; i<count_; ++i){
		agents_[i]->update();
	}
}*/
	
AbmAgent* AbmAgentList::getAgent(long int i){
		if(i < count_)
			return agents_[i];
		else
			return NULL;

} 
long int AbmAgentList::getCount(){
	return count_;
}
void AbmAgentList::setEnvironment(AbmEnvironment *environment){
	environment_= environment;
}
AbmEnvironment* AbmAgentList::getEnvironment(){
	return environment_;
}

	// Destructor
AbmAgentList::~AbmAgentList(){
	for(long int i=0; i<count_; ++i){
		delete agents_[i];
	}
}

int AbmAgentList::addAgent(AbmAgent* agent){
	if(count_ < size_){
		agents_[count_] = agent;
	}
	else {
		long int tempSize = size_+ABMAGENTLIST_SIZE;
		AbmAgent **tempAgents = new AbmAgent*[tempSize];
		cout << "Resizing list " << count_ << " \t " << tempSize << endl;

		for(long int i=0; i<tempSize;++i){
			if(i<size_){
				tempAgents[i] = agents_[i];
			}
			else {
				tempAgents[i] = NULL;
			}
		}
		
		tempAgents[count_] = agent;
		
		size_ = tempSize;
		delete agents_;
		agents_ = tempAgents;
		
	}
	count_++;
	return 1;

}

void AbmAgentList::clearList(){
	for(long int i = 0; i<count_; ++i){
		agents_[i] = NULL;
	}
	count_ = 0;
}

void AbmAgentList::printAgentsStates(){
	for(long int i=0; i<count_; ++i){
		 agents_[i]->printState();
		//cout << m_agents[i]->Print_State() << endl;
	}
}

void AbmAgentList::deleteEntireList(){
	for (int i = 0; i<count_; ++i) {
		delete agents_[i];
	}
}