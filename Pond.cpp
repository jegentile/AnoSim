/*
 *  Pond.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Pond.h"
#include <math.h>

Pond::Pond(){
	return;
}

double Pond::getRoomForEggs(){
	double n = pow(0.9999,agentLists_[0]->getCount());
	return n;
}

void Pond::applyDeathRate(){
	
}

void Pond::clearInbox(){
	int count = inbox_->getCount();
	cout << "In Pond. Adding " << count << "agents "<< endl;
	for (int i=0; i<count; ++i) {
		agentLists_[0]->addAgent(inbox_->getAgent(i));
	}
	agentLists_[0]->clearList();
}