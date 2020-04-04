#pragma once
#include "Sprite.h"
#include "Bullet.h"
#include <time.h>
#include <random>

class Eye : public Sprite
{
public:
	Eye(SDL_Renderer* a_renderer, const char* filename, int sizeX, int sizeY, float a_speed);
	~Eye();

	void update(float deltaTime) override;
	void onCollisionWith(const Sprite& other) override;

	float shootInterval = 6.0f; // time between shots
	float shootTimer = rand() %6 +1; // timer which
	
	void shoot();
};