#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace gordon {

class Swarm {
private:
	Particle * m_pParticles;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	void update(int elapsed);
	const static int NPARTICLES = 4000; // number of partilces
	const Particle * const getParticles() {return m_pParticles;};
};

}

#endif