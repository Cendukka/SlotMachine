/*
 ** Author: Samuli Lehtonen
 ** Student number: 301121118
 ** Creation date: 15.02.2020
 ** Game app description: This is a simple one line slotmachine that includes 5 different bets,
 **							jackpot and different winning conditions.
 ** Attribution credits:
 ***		Background slotmachine image ~~ Vecteezy.com
 ***		Slot Images ~~ opengameart.org
 ***		Some files to have basic gameapp structure:
 ****				Game, Collisionmanager,Soundmanager, Texturemanager, Displayobject, Gameobject,
 ****				main, Scene and util provided by ~~ Tom Tsiliopoulos
 ** Revision history: 15.02.2020 ~~ Version 1.0 created
 */




// Core Libraries
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <string>

#include <math.h>
#include <Windows.h>

// 3rd Party Libraries
#include <GLEW\glew.h>
#include <glm\vec3.hpp>
#include <glm\gtx\color_space.hpp>


#include "TextureManager.h"
#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
	Uint32 frameStart, frameTime;
	UINT32 frames = 0;


	// show console
	AllocConsole();
	freopen("CON", "w", stdout);


	TheGame::Instance()->init("The Epic Slot Machine", 100, 100, 800, 600, false);

	while (TheGame::Instance()->running())
	{
		frameStart = SDL_GetTicks();

		TheGame::Instance()->handleEvents();
		TheGame::Instance()->update();
		TheGame::Instance()->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}

		frames++;
		TheGame::Instance()->setFrames(frames);

	}

	TheGame::Instance()->clean();
	return 0;
}

