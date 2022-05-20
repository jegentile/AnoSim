/*
 *  AbmSimpleAgentList.h
 *  Untitled
 *
 *  Created by James E. Gentile on 2/17/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ABM_SIMPLE_AGENT_LIST_H
#define ABM_SIMPLE_AGENT_LIST_H

#include <iostream>
#include "AbmClasses.h"
#include "AbmAgentList.h"

class AbmSimpleAgentList: public AbmAgentList{
	
public:
	// Constructors
	
	 AbmSimpleAgentList();
	 AbmSimpleAgentList(AbmEnvironment *env);
	 AbmSimpleAgentList(int numOfIntialAgents, AbmEnvironment* my_env);
	 	
	void update();									// performs periodic updating on the list.
	
	// Destructor
	~AbmSimpleAgentList();
	
};

#endif