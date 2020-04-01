// Game class with a game loop (input, update, draw)
#pragma once
#include <SDL.h>
#include "Bullet.h"
#include "SpriteManager.h"
#include "Ship.h"

class Game
{
	// For framerate
	int targetFramerate = 30;
	int frameDelayMs = 1000/targetFramerate;
	Uint32 frameEndTimeMs;
	Uint32 lastFrameStartTimeMs;
	Uint32 timeSinceLastFrame;

	// for gameplay
	float deltaTime;
	float gameTime = 0;

	// A pointer points to an object and is denoted by a "*" in declaration. So g_pWindow is a Pointer which *points* to an object of type SDL_Window
	SDL_Window* pWindow = nullptr;
	SDL_Renderer* pRenderer = nullptr;

	// to know when to quit
	bool isRunning;

	//bool buttonsPressed[16] = {false};

public:
	Bear* bear;
	Sprite* spike;
	Sprite* background1;
	Sprite* background2;
	Bullet* bullet;
	SpriteManager spriteManager;

	Game();
	Game(const char* windowName, int windowSizeX, int windowSizeY);
	~Game();

	// start the game loop
	void run();

	// game loop
	void input();

	// update your game world in here!
	void update();

	// draw your sprites here!
	void draw();
	
	// called at the end of the loop
	void waitForNextFrame();

	// stop running the gane
	void quit();

	// clean memory related to the Game object.
	void cleanup();
};





