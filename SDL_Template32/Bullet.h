#pragma once
#include "Sprite.h"
class Bullet :
	public Sprite
{
public:
	Bullet();
	Bullet(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, float a_speed);

	float speed = 300;
	float lifeTime = 5;

	void update(float deltaTime) override;
	void onCollisionWith(const Sprite& other) override;
};

