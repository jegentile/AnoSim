/*
 *  Landscape.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 2/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Landscape.h"
#include "MosquitoList.h"

Landscape::Landscape(){
	inbox_ = new AbmSimpleAgentList();
	numOfSubContainers_ = 0;
	//subEnvironments_ = new AbmEnvironment*[1];
	//subEnvironments_[1] = NULL;
	numOfAgentLists_ = 1;
	agentLists_ =  (AbmAgentList**)new MosquitoList*[numOfAgentLists_];
	agentLists_[0] = new MosquitoList();
	
	numOfPonds_ = 1;
	ponds_ = new Pond*[numOfPonds_];
	
	return;
}

void Landscape::clearInbox(){
	
	long int count = inbox_->getCount();
	
	//cout << name_ << " receiving " <<   count << endl;
	
	for(long int i = 0; i<count; ++i){
		agentLists_[0]->addAgent(inbox_->getAgent(i));
	}
}