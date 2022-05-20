/*
 *  AbmAgent.cpp
 *  
 *
 *  Created by Gregory Davis on 1/31/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#include "AbmAgent.h"

AbmAgent::AbmAgent(){
}


AbmAgent::AbmAgent(AbmEnvironment *environment){
	environment_ = environment;
}


long int AbmAgent::getX() {
	return xPosition_;
}

long int AbmAgent::getY() {
	return yPosition_;
}

double AbmAgent::getAgeInHours() {
	return ageInHours_;
}

double AbmAgent::getAgeInDays() {
	return ageInHours_ / 24.0;
}

void AbmAgent::setPosition (int x, int y) {
	xPosition_ = x;
	yPosition_ = y;
}

void AbmAgent::updatePosition (int diffx, int diffy){
	xPosition_ += diffx;
	yPosition_ += diffy;
}	

void AbmAgent::setEnvironment(AbmEnvironment *environment) {
	environment_ = environment;
}

AbmEnvironment* AbmAgent::getEnvironment() {
	return environment_;
}

void build(AbmEnvironment *environment, long int xPos, long int yPos, double age){
	return;
}



void AbmAgent::update() {
	if (environment_) {
		ageInHours_ +=environment_->getHoursInTimeStep();
	}
	if (strategy_){
		strategy_->update();
	}
}

AbmAgent::~AbmAgent(){
	if (strategy_)
		delete strategy_;
}

void AbmAgent::printState(){
	strategy_->printCurrentState();
}

void AbmAgent::setName(string name){
	name_ = name;
}
string AbmAgent::getName(){
	return name_;
}	
