/*
 *  AbmAgentList.h
 *  
 *
 *  Created by Gregory Davis on 1/31/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ABMAGENTLIST_H
#define ABMAGENTLIST_H

#ifndef ABMAGENTLIST_SIZE
#define ABMAGENTLIST_SIZE 10000
#endif


#include <iostream>
#include "AbmClasses.h"
//#include "AbmAgent.h"

class AbmEnvironment;
class AbmAgent;

class AbmAgentList{

protected:
	AbmAgent  **agents_;						// list of agents held by this object
	AbmEnvironment *environment_;					// reference to an environment object
	long int size_;
	long int count_;
	long int indexToEnd_;
	
public:
	// Constructors
/*
	AbmAgentList();
	AbmAgentList(AbmEnvironment *env);
	AbmAgentList(int numOfIntialAgents, AbmEnvironment* my_env);
*/	
	virtual void update() = 0;									// performs periodic updating on the list.
	
	
	// Methods/Accessors
	AbmAgent* getAgent(long int i);					// returns an agent from the list specified by index i. 
	long int getCount();							// returns the number of agents the list contains.
	void setEnvironment(AbmEnvironment *environment);// updates the current reference to the environment object
	AbmEnvironment* getEnvironment();				// returns the current reference to the environment object
	int addAgent(AbmAgent* agent);
	void printAgentsStates();
	void clearList();
	void deleteEntireList();
	// Destructor
	~AbmAgentList();
	
};

#endif