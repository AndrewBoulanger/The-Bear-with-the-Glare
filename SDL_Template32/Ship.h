#pragma once
#include "Sprite.h"
class Bear :
	public Sprite
{

	int health = 3;
public:

	float speed = 5.0f;
	float velX = 0;
	float velY = 0;

	Bear(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, int num_frames = 1);
	~Bear();

	void update(float deltaTime) override;
	void tryShoot();
	void moveBy(int x, int y);

	// determine when you can shoot
	float shootInterval = 0.1; // time between shots
	float shootTimer = 0; // timer which
};

