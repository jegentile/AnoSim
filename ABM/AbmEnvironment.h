/*
 *  AbmEnvironment.h
 *  Untitled
 *
 *  Created by James E. Gentile on 1/29/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ABMENVIRONMENT_H
#define ABMENVIRONMENT_H

//#include "AbmClasses.h"
#include "AbmContainer.h"
#include "AbmEnvironmentalVariable.h"

#include "AbmAgentList.h"
class AbmAgentList;



class AbmEnvironment:public AbmContainer{
protected:
	AbmEnvironmentalVariable* enviroVarList_;
	int numOfEnviroVars_;
	int numOfSubEnvironments_;
	AbmContainer* parentContainer_;
	
	AbmEnvironment **subEnvironments_;
	AbmAgentList** agentLists_;
	int numOfAgentLists_;
	int indexOfAgentList_;
	
	
	int numOfSubContainers_;
	int indexOfSubConters_;
	
public:
	AbmEnvironment();
	AbmEnvironment(AbmContainer* parent, int numOfAgentLists, int numOfSubContainers);
	AbmEnvironmentalVariable* getEnvironmentalVariable(int i);
	void setSizeOfEnvironmentalVariableList(int size);
	void setEnvironmentalVariable(int i,float value);
	void setNumOfAgentLists(int num);
	int addAgentList(AbmAgentList* agentList);
	
	//Overrides from AbmContainer
	void update();
	void clearInbox();
	
	
	~AbmEnvironment();
	
	
};

#endif