/*
 * Particle.cpp
 *
 *  Created on: Dec 4, 2020
 *      Author: jzhong
 */
#include <stdlib.h>
#include <math.h>
#include "Particle.h"

namespace caveofprogramming {

Particle::Particle():m_x(0), m_y(0) {


}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::init(){
	m_x = 0;
	m_y = 0;

	m_direction = (2* M_PI * rand())/RAND_MAX;
	m_speed = (0.04 * rand())/RAND_MAX;

	// make it not uniform distributed
	m_speed *= m_speed;
}

void Particle::update(int interval){

	m_direction += interval*0.00002;

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);
	m_x += xspeed * interval;
	m_y += yspeed * interval;

	if(m_x < -1 || m_x > 1 || m_y < -1 || m_y >1){
		init();
	}

	if(rand() < RAND_MAX/100){
		init();
	}
}

}


