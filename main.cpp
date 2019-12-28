#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include "Screen.h"
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;
using namespace gordon;

int main(){

	srand(time(NULL)); // <-------- chnage in program compared ot other programe

	Screen screen;
	if(screen.init() == false ){
		cout << "Error Itialzing SDL. "<< endl;
	}

	Swarm swarm;

	while(true) {//update partilces                                  //sin or cos cos starts at value of zero
		// draw paritcles
		// events( while loop or game loop)       in his loop the particles are changing color not moving
		
		int elapsed = SDL_GetTicks();

		//screen.clear();
		swarm.update(elapsed); // 
	
		unsigned char green = (unsigned char)((1 + sin(elapsed*0.0001))*128); //sin produces smooth change of colors
		unsigned char red = (unsigned char)((1 + sin(elapsed*0.0002))*128); //they 0.001 is how fast is changes 
		unsigned char blue = (unsigned char)((1 + sin(elapsed*0.0003))*128);

		const Particle * const pParticles = swarm.getParticles();

		for (int i=0; i<Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];
		
			int x = (particle.m_x + 1)*Screen::SCREEN_WIDTH/2;
			int y = particle.m_y *Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);             //setting pixel data
		}

		screen.boxBlur();

		screen.update();   //updatung screen

		if (screen.processEvents() == false) {
			break;
		}

	}
	
	screen.close();

	return 0;
 }