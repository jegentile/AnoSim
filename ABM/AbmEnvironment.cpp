/*
 *  AbmEnvironment.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 2/1/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "AbmEnvironment.h"


AbmEnvironment::AbmEnvironment(){
	return;
}
AbmEnvironment::AbmEnvironment(AbmContainer* parent, int numOfAgentLists, int numOfSubContainers){
	agentLists_ = new AbmAgentList*[numOfAgentLists];
	numOfAgentLists_ = numOfAgentLists;
	indexOfAgentList_ = 0;
	for(int i=0; i<numOfAgentLists_;++i)
		agentLists_[i] = NULL;
	
	numOfSubContainers_ = numOfSubContainers;
	subEnvironments_ = new AbmEnvironment*[numOfSubContainers_];
	indexOfSubConters_= 0;
	for(int i=0; i<numOfSubContainers; ++i)
		subEnvironments_[i]=NULL;
	
	parentContainer_ = parent;
	
}
AbmEnvironmentalVariable* AbmEnvironment::getEnvironmentalVariable(int i){
	return NULL;//
}

void AbmEnvironment::setEnvironmentalVariable(int i,float value){
	return;
}

void AbmEnvironment::setSizeOfEnvironmentalVariableList(int i){
	enviroVarList_[i];// = AbmEnvironmental_Variable[i];
}

void AbmEnvironment::setNumOfAgentLists(int num){
	agentLists_ = new AbmAgentList*[num];
	numOfAgentLists_ = num;
	indexOfAgentList_ = 0;
}
int AbmEnvironment::addAgentList(AbmAgentList* agentList){
	if(indexOfAgentList_ < numOfAgentLists_){
		agentLists_[indexOfAgentList_] = agentList;
		indexOfAgentList_++;
		return 1;
	}
	else{
		   return 0;
	}
}


void AbmEnvironment::update(){
	cout << "\t\tUpdating Environment"<<endl;
	clearInbox();
	updateTime();
	
	for(int i=0; i<numOfSubContainers_; ++i)
		if(subEnvironments_[i])
			subEnvironments_[i]->update();
	
	for(int i=0; i<numOfAgentLists_;++i)
		if(agentLists_[i])
			agentLists_[i]->update();
}
void AbmEnvironment::clearInbox(){
	cout << "Landscape " << inbox_->getCount()<< endl;
	return;
}

AbmEnvironment::~AbmEnvironment(){
	return;
}