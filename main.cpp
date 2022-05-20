#include <iostream>

#include "Pond.h"
#include "LandScape.h"
#include "AbmSimulation.h"
#include "AbmAgent.h"
#include "AbmAgentList.h"
#include "Mosquito.h"
#include "MosquitoList.h"


#define NUMBER_OF_INITIAL_AGENTS 1
#define AbmENV_VAR_TEMPERATURE 0

#define INITIAL_AGENT_COUNT 100000

#define ABMDEBUG 1

int main (int argc, char * const argv[]) {
	
	MosquitoList list;
	AbmSimulation sim(1,2);
	Landscape land1;
	Landscape land2;
	
	sim.addSubContainer(&land1);
	sim.addSubContainer(&land2);
	
	land1.setParent(&sim);
	land2.setParent(&sim);
	
	sim.setName("Simulation!");
	land1.setName("Land 1");
	land2.setName("Land 2");
	
	
	for (unsigned int i = 0; i<5; ++i) {
		Mosquito *mosq = new Mosquito(&land1);
		mosq->setEnvironment(&land1);
		mosq->ii = i;
		sim.addToInbox(mosq);
	}
	
	for (unsigned int i = 0; i<5; ++i) {
		Mosquito *mosq = new Mosquito(&land2);
		mosq->setEnvironment(&land2);
		mosq->ii = i;
		sim.addToInbox(mosq);
	}
	
	sim.update();
	sim.update();
	sim.update();
	sim.update();
	sim.update();
	
	
	
	return 0;
	
	
}

