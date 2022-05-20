/*
 *  ABMResponder.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 2/5/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "AbmContainer.h"
#include <iostream>

void AbmContainer::updateTime(){

	if(parent_){
		
		hour_ = parent_->getHour();
		day_ = parent_->getDay();;
		year_ = parent_->getYear();
		stopYear_ = parent_->getStopYear();
		stopDay_ = parent_->getStopDay();
		stopHour_ = parent_->getStopHour();
		absHour_ = parent_->getAbsHour();
		hoursInTimeStep_ = parent_->getHoursInTimeStep();
		
	//	cout << name_ ": setting time " << absHour_ << endl;
	}
		
}

void AbmContainer::addToInbox(AbmAgent *agent){
	inbox_->addAgent(agent);
	return;
}

unsigned long int AbmContainer::getHour(){
	return hour_;
}

unsigned long int AbmContainer::getDay(){
	return day_;
}

int AbmContainer::getYear(){
	return year_;
}

int AbmContainer::getStopYear(){
	return stopYear_;
}

unsigned long int AbmContainer::getStopDay(){
	return stopDay_;
}

unsigned long int AbmContainer::getStopHour(){
	return stopHour_;
}

unsigned long int AbmContainer::getAbsHour(){
	name_;
	return absHour_;
}

float AbmContainer::getHoursInTimeStep(){
	return hoursInTimeStep_;
}

void AbmContainer::setParent(AbmContainer* parent){
	parent_ = parent;
	updateTime();
}

AbmContainer::~AbmContainer(){
	return;
}

void AbmContainer::setName(string name){
	name_ = name;
}
string AbmContainer::getName(){
	return name_;
}	

AbmContainer* AbmContainer::getParentContainer(){
	return parent_;
}
