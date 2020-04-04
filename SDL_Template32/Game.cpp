#include "Game.h"
#include <iostream>
#include <SDL_image.h>


Game::Game()
{
}

Game::Game(const char* windowName, int windowSizeX, int windowSizeY)
{
	int flags = SDL_INIT_EVERYTHING;

	if (SDL_Init(flags) == 0) // if initialized SDL correctly...
	{
		// Create the window
		pWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSizeX, windowSizeY, SDL_WINDOW_SHOWN);

		if (pWindow != nullptr)
		{
			// Create the renderer
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_PRESENTVSYNC);

			if (pRenderer != nullptr)
			{
				IMG_Init(IMG_INIT_PNG);
			}
			if (Mix_Init(MIX_INIT_MP3) != 0)
			{
				std::cout << "mix failed to initialize" << std:: endl;
			}

			Mix_OpenAudio(22400, AUDIO_U16, 8, 2048);
			bgm = Mix_LoadWAV("Assets/bgm.mp3");

			laser_SFX = Mix_LoadWAV("Assets/Laser.WAV");
		}
	}
}

Game::~Game()
{
}

void Game::run()
{
	
	background1 = new Sprite(pRenderer, "Assets/background1.bmp", 800, 600);
	background2 = new Sprite(pRenderer, "Assets/background2.bmp", 800, 600);

	bear = new Bear(pRenderer, "Assets/bear_ani.png", 116, 110);
	bear->tag = SpriteTag::PLAYER;

	spriteManager.add(background1);
	spriteManager.add(background2);
	spriteManager.add(bear);

	background1->setPosition(0,0);
	background2->setPosition(800, 0);
	bear->setPosition(400, 400);

	
	Mix_PlayChannel(0, bgm, -1);
	Mix_Volume(0, 64);

	isRunning = true;
	
	// set initial delta time
	deltaTime = 1.0f / targetFramerate;
	lastFrameStartTimeMs = SDL_GetTicks();

	while (isRunning)
	{
		input();
		update();
		draw();
		waitForNextFrame();
	}

	cleanup();
}

void Game::input()
{
	SDL_Event sdlEvent;

	float movementSpeed = 200;

	static bool spacePressed = false;


	while (SDL_PollEvent(&sdlEvent))
	{
		if (sdlEvent.type == SDL_QUIT)
		{
			isRunning = false;
		}
		else if (sdlEvent.type == SDL_KEYDOWN)
		{
			switch (sdlEvent.key.keysym.sym)
			{
			case(SDLK_SPACE):
			{
				if (spacePressed == false)
				{
					spacePressed = true;
					Mix_PlayChannel(1, laser_SFX, -1);
				}
				break;
			}
			case(SDLK_LEFT):
			{
				bear->velX = -1;
				break;
			}
			case(SDLK_RIGHT):
			{
				bear->velX=1;
				break;
			}
			case(SDLK_UP):
			{
				bear->velY=-1;
				break;
			}
			case(SDLK_DOWN):
			{
				bear->velY=1;
				break;
			}

			case(SDLK_ESCAPE):
			{
				quit();
				break;
			}
			}
		}

		if (sdlEvent.type == SDL_KEYUP)
		{
			switch (sdlEvent.key.keysym.sym)
			{
			case(SDLK_SPACE):
			{
				spacePressed = false;
				Mix_HaltChannel(1);
				break;
			}
			case(SDLK_LEFT):
			{
				bear->velX = 0;
				break;
			}
			case(SDLK_RIGHT):
			{
				bear->velX = 0;
				break;
			}
			case(SDLK_UP):
			{
				bear->velY = 0;
				break;
			}
			case(SDLK_DOWN):
			{
				bear->velY = 0;
				break;
			}
			}
		}
		
	}

		if (spacePressed)
		{
			bear->tryShoot();
			
		}
}

void Game::update()
{
	spriteManager.updateAll(deltaTime);

	background1->moveBackground(backgroundSpeed);
	background2->moveBackground(backgroundSpeed);

	bear->boundsCheck();

	enemyTimer -= deltaTime;
	if (enemyTimer <= 0)
	{
		Eye* newEnemy = new Eye(pRenderer, "Assets/eye.png", 50, 65, 60);
		newEnemy->setPosition(800 + rand() % 100,rand() % (600-65));
		

		spriteManager.add(newEnemy);
		newEnemy->setTarget(&(bear->dst));
		enemyTimer = enemiesSpawnDelay;
	}

}


void Game::draw()
{
	SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(pRenderer);
	
	spriteManager.drawAll();
	
	SDL_RenderPresent(pRenderer);
}

void Game::waitForNextFrame()
{
	Uint32 gameTimeMs = SDL_GetTicks();
	timeSinceLastFrame = gameTimeMs - lastFrameStartTimeMs;

	if (timeSinceLastFrame < frameDelayMs)
	{
		SDL_Delay(frameDelayMs - timeSinceLastFrame);
	}

	frameEndTimeMs = SDL_GetTicks();
	deltaTime = (frameEndTimeMs - lastFrameStartTimeMs)/1000.f;
	gameTime = frameEndTimeMs / 1000.f;
	lastFrameStartTimeMs = frameEndTimeMs;
}

void Game::quit()
{
	isRunning = false;
}

void Game::cleanup()
{
	bullet->cleanup();
	spriteManager.cleanup();
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
	std::cout << "Goodbye World" << std::endl;
}
