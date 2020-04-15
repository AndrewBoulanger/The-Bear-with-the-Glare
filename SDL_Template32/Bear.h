#pragma once
#include "Sprite.h"
class Bear :
	public Sprite
{


public:
	int health = 10;

	float speed = 180;
	float velX = 0;
	float velY = 0;

	Bear(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, int num_frames = 1);
	~Bear();

	void update(float deltaTime) override;
	void onCollisionWith(const Sprite& other) override;
	bool tryShoot();
	void moveBy(int x, int y, float deltaTime);
	void boundsCheck();

	// determine when you can shoot
	float shootInterval = 0.2; // time between shots
	float shootTimer = 0; // timer which
};

