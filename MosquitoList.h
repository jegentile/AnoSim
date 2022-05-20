/*
 *  MosquitoList.h
 *  Untitled
 *
 *  Created by James E. Gentile on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef MOSQUITO_LIST_H
#define MOSQUITO_LIST_H

#include "ABM/AbmAgentList.h"
#include "ABM/AbmAgent.h"

class MosquitoList: public AbmAgentList{

public:
	MosquitoList();
	MosquitoList(AbmEnvironment *env);
	MosquitoList(int numOfIntialAgents, AbmEnvironment* my_env);
	
	//int addAgent(AbmAgent* agent);
	void applyDeathRate();
	void update();

};

#endif