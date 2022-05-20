/*
 *  AbmAgent.h
 *  
 *
 *  Created by Gregory Davis on 1/31/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ABMAGENT_H
#define ABMAGENT_H

#include <iostream>
#include <string>
using std::string;
#include "AbmEnvironment.h"
#include "AbmSimulation.h"
#include "AbmState.h"
#include "AbmClasses.h"
#include "AbmStrategy.h"

class AbmStrategy;

class AbmAgent{

protected:
	double ageInHours_;						// age of the agent in hours
	long int xPosition_;									// x position of the agent
	long int yPosition_;									// y position of the agent
	AbmEnvironment *environment_;					// reference to an environment object
	AbmStrategy *strategy_;
	string name_;

public:
	// Constructors
	AbmAgent();
	AbmAgent( AbmEnvironment *environment);
	void build(AbmEnvironment *environment, long int xPos, long int yPos, double age);
	
	// Methods/Accessors
	long int getX();								// returns the agent's x position
	long int getY();								// returns the agent's y position
	double getAgeInHours();					// returns the agent's age (in hours)
	double getAgeInDays();						// returns the agent's age (in days)
	void setPosition (int x, int y);				// sets the absolute position of the agent
	void updatePosition (int diffx, int diffy);	// updates the agent position relative to its current position
	
	void setEnvironment(AbmEnvironment *env);		// updates the current reference to the environment object
	AbmEnvironment* getEnvironment();				// returns the current reference to the environment object
	
	void update();									// performs periodic updating on the list.
	
	void printState();
	void setName(string name);
	string getName();
	
	// Destructor
	~AbmAgent();
	
};

#endif
