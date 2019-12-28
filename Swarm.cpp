#include "Swarm.h"
#include <stdlib.h>

namespace gordon{


Swarm::Swarm(): lastTime(0){
	m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
	delete [] m_pParticles;
};
void Swarm::update(int elapsed){

	int interval = elapsed- lastTime;//added

	for(int i=0; i<Swarm::NPARTICLES; i++){
	m_pParticles[i].update(interval); //added		   
	}

	lastTime = elapsed;//added
}

}
/*
void Swarm::update(int ticks){
	for(int i=0; i<NPARTICLES; i++){
		m_pParticles[i].update(ticks - m_lastTime, ticks);
	}
*
	m_lastTime = ticks;
}

}
*///: m_lastTime(0), m_pParticles(NULL)