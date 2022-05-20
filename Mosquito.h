/*
 *  Mosquito.h
 *  Untitled
 *
 *  Created by James E. Gentile on 2/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#include "ABM/AbmAgent.h"
#include "MosquitoStrategy.h"

class Mosquito: public AbmAgent{
public:
	Mosquito(AbmEnvironment* environment);
	unsigned int ii;
	void layEggs();
};
