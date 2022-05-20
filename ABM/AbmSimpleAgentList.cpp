/*
 *  AbmSimpleAgentList.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 2/17/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "AbmSimpleAgentList.h"

/*
 *  AbmAgentList.cpp
 *  
 *
 *  Created by Gregory Davis on 1/31/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "AbmSimpleAgentList.h"

#include <iostream>
#include "AbmEnvironment.h"
#include "AbmAgent.h"
#include "AbmSimulation.h"
#include "AbmClasses.h"


// Constructors


AbmSimpleAgentList::AbmSimpleAgentList(){
	agents_ = new AbmAgent*[ABMAGENTLIST_SIZE];
	for (long int i=0; i<ABMAGENTLIST_SIZE; ++i) {
		agents_[i] = NULL;
	}
	environment_ = NULL;
	size_= ABMAGENTLIST_SIZE;
	count_ = 0;
	indexToEnd_= 0;
}
 
AbmSimpleAgentList::AbmSimpleAgentList( AbmEnvironment *environment){
environment_ = environment;
}	
 
AbmSimpleAgentList::AbmSimpleAgentList(int numOfInitialAgents,AbmEnvironment* environment){
environment_ = environment;
count_= 0;
size_ = numOfInitialAgents;
	agents_ = new AbmAgent*[numOfInitialAgents];
	for(long int i = 0; i < numOfInitialAgents; ++i){
		agents_[i] = NULL;
	}
}
 

	void AbmSimpleAgentList::update(){
	for(long int i=0; i<count_; ++i){
	agents_[i]->update();
	}
}

AbmSimpleAgentList::~AbmSimpleAgentList(){
	return;
}
