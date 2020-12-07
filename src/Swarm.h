/*
 * Swarm.h
 *
 *  Created on: Dec 4, 2020
 *      Author: jzhong
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"
namespace caveofprogramming {

class Swarm {
private:
	Particle *m_pParticles; // pointer to particle array
	int lastTime;
public:
	const static int NPARTICLES = 5000;
	Swarm();
	virtual ~Swarm();
	// make sure it's not changed outside the class
	const Particle * const getParticles(){return this->m_pParticles;};
	void update(int a);
};

} /* namespace caveofprogramming */

#endif /* SWARM_H_ */
