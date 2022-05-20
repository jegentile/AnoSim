/*
 *  ABMResponder.h
 *  Untitled
 *
 *  Created by James E. Gentile on 2/5/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ABM_CONTAINER_H
#define ABM_CONTAINER_H

#include <iostream>
#include "AbmSimpleAgentList.h"
#include <string>
using std::string;
class AbmAgent;

class AbmContainer{
protected:
	unsigned long int hour_;
	unsigned long int day_;
	int year_;
	int stopYear_;
	unsigned long int stopDay_;
	unsigned long int stopHour_;
	unsigned long int absHour_;
	float hoursInTimeStep_;
	
	AbmContainer* parent_;
	AbmSimpleAgentList* inbox_;
	
	string name_;
	
public:
	

	virtual void clearInbox() = 0;
	void addToInbox(AbmAgent* agent);
	virtual void update() = 0;

	void updateTime();

	unsigned long int getHour();
	unsigned long int getDay();
	
	int getYear();
	int getStopYear();
	
	unsigned long int getStopDay();
	unsigned long int getStopHour();
	unsigned long int getAbsHour();
	
	float getHoursInTimeStep();
	void setParent(AbmContainer *parent);
	
	void setName(string name);
	string getName();
	
	AbmContainer* getParentContainer();
	
	~AbmContainer();
};

#endif