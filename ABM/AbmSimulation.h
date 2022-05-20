/*
 *  AbmSimulation.h
 *  Untitled
 *
 *  Created by James E. Gentile on 1/29/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ABMSIMULATION_H
#define ABMSIMULATION_H

#include <iostream>

#include "AbmContainer.h"

class AbmSimulation:public AbmContainer{

protected:

	int numOfSubContainers_;
	int atSubContainerIndex_; 
	
	AbmContainer** subContainers_;

	
public:
	AbmSimulation();
	AbmSimulation(float hoursInTimeStep,int numOfSubContainers);
	void addSubContainer(AbmContainer* subContainer);
	void setNumberOfSubContainers(int numOfSubContainers);
	
	void setHoursInTimeStep(float hoursInTimeStep);
	
	float getHoursInTimeStep();
	void setEndingDay(long int day);
	long int getTime();
	~AbmSimulation();
	void run();
	long int getAbsHour();

	void step(); //For Debugging
	void updateTime();
	
	
	void sendAgentListToParent();
	void receiveAgentList();
	
	void clearInbox();
	void update();
	
	
};

#endif