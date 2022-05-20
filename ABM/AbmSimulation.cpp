/*
 *  AbmSImulation.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 1/29/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "AbmSimulation.h";

#include <iostream>
#include "AbmEnvironment.h"
#include "AbmAgent.h"
#include "AbmAgentList.h"
#include "math.h"
#include "time.h"

#include "../Landscape.h"


AbmSimulation::AbmSimulation(){
	hour_ = 0;
	day_ = 0;
	year_ = 0;
	stopYear_ = 0;
	stopDay_ = 0;
	stopHour_ = 0;
	absHour_ = 0;
	subContainers_ = NULL;
	srand(time(NULL));
	inbox_ = new AbmSimpleAgentList();
	parent_ = NULL;
	
}

AbmSimulation::AbmSimulation(float hoursInTimeStep,int numOfSubContainers){
	
	hour_ = 0;
	day_ = 0;
	year_ = 0;
	stopYear_ = 0;
	stopDay_ = 0;
	stopHour_ = 0;
	absHour_ = 0;
	
	
	hoursInTimeStep_ = hoursInTimeStep;
	numOfSubContainers_	= numOfSubContainers;
	subContainers_ = new AbmContainer*[numOfSubContainers_];
	atSubContainerIndex_ = 0;
	srand(time(NULL));
	inbox_ = new AbmSimpleAgentList();
	
}

void AbmSimulation::setHoursInTimeStep(float hoursInTimeStep){
	hoursInTimeStep_ = hoursInTimeStep;
	return;
}

void AbmSimulation::setNumberOfSubContainers(int numOfSubContainers){
	numOfSubContainers_ = numOfSubContainers;
	subContainers_ = new AbmContainer*[numOfSubContainers_];
}

float AbmSimulation::getHoursInTimeStep(){
	return hoursInTimeStep_;
}

void AbmSimulation::setEndingDay(long int day){
	stopDay_= day;
}

long int AbmSimulation::getTime(){
	return 0;
}

void AbmSimulation::addSubContainer(AbmContainer* subContainer){
	subContainers_[atSubContainerIndex_] = subContainer;
	atSubContainerIndex_++;
}


void AbmSimulation::run(){
	
	while(day_ < stopDay_){
		updateTime();
		if(subContainers_){
			for(int i=0; i<numOfSubContainers_;++i){
				if(subContainers_[i]){
					subContainers_[i]->update();
				}
			}			
		}
	//	cout << "Time is " << m_day << " " << m_hour << endl; 
		
	}
}

AbmSimulation::~AbmSimulation(){
	if(subContainers_){
		for(int i=0; i<numOfSubContainers_;++i){
			if(subContainers_[i]){
				delete subContainers_[i];
			}
		}			
	}
}
	
long int AbmSimulation::getAbsHour(){
 	return absHour_;
}

void AbmSimulation::updateTime(){
	hour_+= hoursInTimeStep_;
	absHour_ += hoursInTimeStep_;
	if(hour_ >= 24){
		day_++;
		hour_ = hour_-24;
	}
	return;
}

void AbmSimulation::update(){
	updateTime();
	clearInbox();
	if(subContainers_){
		for(int i=0; i<numOfSubContainers_;++i){
			if(subContainers_[i]){
				subContainers_[i]->update();
			}
		}			
	}	
}

void AbmSimulation::step(){
	update();
}


void AbmSimulation::clearInbox(){
	cout << "This is the simulation. I have " << inbox_->getCount() << "agents in my inbox." << endl;
	long int count = inbox_->getCount();
	for(long int i = 0; i<count; ++i){
		AbmAgent* agt = inbox_->getAgent(i);
		AbmEnvironment* destEnv = agt->getEnvironment();
		for (int j = 0; j<numOfSubContainers_; ++j) {
			if(destEnv == subContainers_[j]){
				Landscape* t = (Landscape*)destEnv;
				cout << "Sending to " << t->getName() << endl;
				subContainers_[j]->addToInbox(agt);
				
			}
		}
	}
	inbox_->clearList();
	return;
}
