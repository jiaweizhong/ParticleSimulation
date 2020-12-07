//============================================================================
// Name        : SDLWindow.cpp
// Author      : Jiawei Zhong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
#include "Particle.h"
#include "Screen.h"
using namespace std;
using namespace caveofprogramming;

int main() {

	// set the random seed
	srand(time(NULL));

	Screen screen;

	if(screen.init() == false){
		cout << "Error initializing SDL." << endl;
	}

	Swarm swarm;

	// game loop
	while(true){
		// update the particles
		int elapsed = SDL_GetTicks();
		// clear particles
		// screen.clear();
		// update the particle location
		swarm.update(elapsed);

		// random pixel color (0*128 ~ 2*128 convert to hex)
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

		// Draw particles
		const Particle *const pParticles = swarm.getParticles();
		for(int i = 0; i < Swarm::NPARTICLES; i++){
			Particle p = pParticles[i];
			// random (x, y) within screen
			int x = (p.m_x+1)*Screen::SCREEN_WIDTH/2;
			int y = p.m_y * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);

		}

		// boxBlur the particles
		screen.boxBlur();

		// Draw the screen
		screen.update();

		// Check for messages
		if(screen.processEvent() == false){
			break;
		}

	}

	screen.close();

	return 0;
}
