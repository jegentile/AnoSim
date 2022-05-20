/*
 *  MosquitoList.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 2/16/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "MosquitoList.h"
#include <math.h>

MosquitoList::MosquitoList(){
	return;
}
MosquitoList::MosquitoList(AbmEnvironment *env){
	
}
MosquitoList::MosquitoList(int numOfIntialAgents, AbmEnvironment* my_env){
	
}


void MosquitoList::applyDeathRate(){
#ifdef ABM_DEBUG
	cout << "Mosquito list applying death rate." << endl;
#endif
	double deathRate = 0.20;
	double population = count_;
	double toDie = round(deathRate*population);
	double at = 0;
	for (double i = 0; i<toDie; ++i) {
		int deleted = 0;
		while(!deleted){
			cout << "in loop" << endl;
			float g = RAND_MAX;
			float r = (float)rand()/RAND_MAX;
			double idx = round(r*population);
			double fract;
			at += idx;
			if(at > population)
				at -=population;
			
			long int address = (long int) at;
			if (agents_[address]) {
				//Kill the agent
				delete agents_[address];
				agents_[address] = NULL;
				deleted = 1;
			}
		}
	}
	long int offset = 0;
	AbmAgent **tempAgents = new AbmAgent*[size_];
	long int tempCount = 0;
	for(long int i=0; i< size_;++i)
		tempAgents[i] = NULL;
	
	for (long int i = 0; i<population; ++i) {
		if(agents_[i]){
			tempAgents[i] = agents_[i-offset];
			tempCount++;
		}
		else{
			offset++;
		}
	}
	count_ = tempCount;
	delete agents_;
	agents_ = tempAgents;
}

void MosquitoList::update(){
	applyDeathRate();
	for(long int i=0; i<count_; ++i){
		agents_[i]->update();
	}
}