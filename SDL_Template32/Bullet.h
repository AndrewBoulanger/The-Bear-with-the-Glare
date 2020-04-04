#pragma once
#include "Sprite.h"
class Bullet :
	public Sprite
{
public:
	Bullet();
	Bullet(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, float a_speed);
	Bullet(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, float a_speed, float targX, float targY);

	float speed = 300;
	float lifeTime = 5;

	float dirX = 1; 
	float dirY = 0;

	float normalizer;

	void update(float deltaTime) override;
	void onCollisionWith(const Sprite& other) override;
};