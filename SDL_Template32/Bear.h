#pragma once
#include "Sprite.h"
class Bear :
	public Sprite
{

	int health = 10;

	int displayFrame = 0;
	int frameCount = 4;

	int frameWidth = 480;
	int frameHeight = 480;

public:

	float speed = 6;
	float velX = 0;
	float velY = 0;

	Bear(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, int num_frames = 1);
	~Bear();

	void update(float deltaTime) override;
	void onCollisionWith(const Sprite& other) override;
	void tryShoot();
	void moveBy(int x, int y);
	void boundsCheck();

	// determine when you can shoot
	float shootInterval = 0.2; // time between shots
	float shootTimer = 0; // timer which
};

