/*
 *  Landscape.h
 *  Untitled
 *
 *  Created by James E. Gentile on 2/10/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ABM/AbmEnvironment.h"
#include "Pond.h"

class Landscape: public AbmEnvironment{
private:
	int numOfPonds_;
	
	Pond **ponds_;
public:
	Landscape();
	void clearInbox();
	void SetNumOfPonds(int numOfPonds);

};