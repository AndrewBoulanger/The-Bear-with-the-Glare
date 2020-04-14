// Game class with a game loop (input, update, draw)
#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "Bullet.h"
#include "SpriteManager.h"
#include "Bear.h"
#include "Eye.h"

#define NUM_KEYBINDS 6


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
	int backgroundSpeed = 2;
	int timeLimit = 10000;

	// A pointer points to an object and is denoted by a "*" in declaration. So g_pWindow is a Pointer which *points* to an object of type SDL_Window
	SDL_Window* pWindow = nullptr;
	SDL_Renderer* pRenderer = nullptr;

	// to know when to quit
	bool isRunning;

	int keyBindings[NUM_KEYBINDS] = { SDLK_SPACE, SDLK_LEFT, SDLK_RIGHT, SDLK_UP, SDLK_DOWN, SDLK_ESCAPE };
	bool buttonsPressed[NUM_KEYBINDS] = {false};

	//for spawn control
	float enemiesSpawnDelay = 2.0f;
	float enemyTimer = 1.0f;

	int score = 0;

public:
	Bear* bear;
	Sprite* background1;
	Sprite* background2;
	Bullet* bullet;
	Mix_Chunk* bgm;
	Mix_Chunk* laser_SFX;
	SpriteManager spriteManager;
	Sprite* health;
	Sprite* healthBar[5];

	Game();
	Game(const char* windowName, int windowSizeX, int windowSizeY);
	~Game();

	// start the game loop
	void run();

	// game loop
	void input();

	// update your game world in here!
	void update();

	void raiseSpeed()
	{
		backgroundSpeed *= 2;
	}

	// draw your sprites here!
	void draw();
	
	// called at the end of the loop
	void waitForNextFrame();

	// stop running the gane
	void quit();

	// clean memory related to the Game object.
	void cleanup();


};





