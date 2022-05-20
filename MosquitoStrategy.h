/*
 *  MosquitoStrategy.h
 *  Untitled
 *
 *  Created by James E. Gentile on 2/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ABM/AbmStrategy.h"

#include "EmergingState.h"
#include "MatingState.h"
#include "BloodMealState.h"
#include "GravidState.h"
#include "OvipositionState.h"

class MosquitoStrategy: public AbmStrategy{
private:
	EmergingState *emergingState_;
	MatingState	*matingState_;
	BloodMealState	*bloodMealState_;
	GravidState *gravidState_;
	OvipositionState *ovipositionState_;

public:
	MosquitoStrategy();
	MosquitoStrategy(AbmEnvironment *environment,AbmAgent* agent);
	void makeStrategy();
	
};