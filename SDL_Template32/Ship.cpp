#include "Ship.h"
#include <iostream>
#include "SpriteManager.h"
#include "Bullet.h"

void Ship::tryShoot()
{
	if (shootTimer <= 0)
	{
		// shoot
		Bullet * b = new Bullet(renderer, "Assets/SpaceShooterRedux/PNG/Power-ups/pill_red.png", 10, 10, 500);
		b->dst.x = dst.x + dst.w/2;
		b->dst.y = dst.y;

		spriteManager->add(b);
		shootTimer = shootInterval;
	}

}

void Ship::update(float deltaTime) 
{
	moveBy(velX, velY);
	shootTimer -= deltaTime;
	if (shootTimer < 0) shootTimer = 0;
}

void Ship::moveBy(int x, int y)
{
	dst.x += x * speed;
	dst.y += y * speed;
}

Ship::Ship(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, int num_frames) : Sprite(renderer, filename, sizeX, sizeY, num_frames)
{
}

Ship::~Ship()
{
}
