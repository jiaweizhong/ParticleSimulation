/*
 * Screen.h
 *
 *  Created on: Dec 4, 2020
 *      Author: jzhong
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

namespace caveofprogramming{
class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
	Screen();
	virtual ~Screen();
	bool init();
	bool processEvent();
	void close();
	void update();
	void setPixel(int x, int y, Uint8 R, Uint8 G, Uint8 B);
	void boxBlur();

private:
	SDL_Window   *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture  *m_texture;
	Uint32		 *m_buffer1; // pixel buffer SDL defined type: Uint32 -> pixel
	Uint32		 *m_buffer2;

};
}

#endif /* SCREEN_H_ */
