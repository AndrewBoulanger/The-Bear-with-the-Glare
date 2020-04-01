#include "Bear.h"
#include <iostream>
#include "SpriteManager.h"
#include "Bullet.h"

void Bear::tryShoot()
{
	if (shootTimer <= 0)
	{
		// shoot
		Bullet * b = new Bullet(renderer, "Assets/bullet.png", 10, 5, 500);
		b->dst.x = dst.x + dst.w*0.6;
		b->dst.y = dst.y + (dst.h*0.33);

		spriteManager->add(b);
		shootTimer = shootInterval;
	}

}

void Bear::update(float deltaTime) 
{
	moveBy(velX, velY);
	shootTimer -= deltaTime;
	if (shootTimer < 0) shootTimer = 0;
}

void Bear::moveBy(int x, int y)
{
	dst.x += x * speed;
	dst.y += y * speed;
}

Bear::Bear(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, int num_frames) : Sprite(renderer, filename, sizeX, sizeY, num_frames)
{
}

Bear::~Bear()
{
}
