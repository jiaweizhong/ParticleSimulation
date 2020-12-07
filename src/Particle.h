/*
 * Particle.h
 *
 *  Created on: Dec 4, 2020
 *      Author: jzhong
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace caveofprogramming {

class Particle {

public:
	// involve lots of particles, public is easier to access
	double m_x;
	double m_y;
	double m_speed;
	double m_direction;
public:
	Particle();
	virtual ~Particle();
	void update(int interval);
private:
	void init();

};
}
#endif /* PARTICLE_H_ */
