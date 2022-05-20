/*
 *  Mosquito.cpp
 *  Untitled
 *
 *  Created by James E. Gentile on 2/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "Mosquito.h"

Mosquito::Mosquito(AbmEnvironment* env){
	ii = 0;
	environment_ = env;
	strategy_ = new MosquitoStrategy(env,this);
	strategy_->printCurrentState();
	return;
}

void Mosquito::layEggs(){
#ifdef ABM_DEBUG
	cout << name_ << " is laying eggs - DEBGUG statement" << endl;
#endif
	cout << name_ << " is laying eggs" << endl;
}