#include "Bear.h"
#include <iostream>
#include "SpriteManager.h"
#include "Bullet.h"

void Bear::tryShoot()
{
	if (shootTimer <= 0)
	{
		// shoot
		Bullet * b = new Bullet(renderer, "Assets/bullet.png", 20, 5, 500);
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
	damageCooldown -= deltaTime;
	if (damageCooldown < 0) damageCooldown = 0;
}
void Bear::onCollisionWith(const Sprite& other) 
{
	if ((other.tag == ENEMY || other.tag == OBSTACLE) && damageCooldown < 1)
	{
		health--;
		damageCooldown = 50;
		std::cout << "collision\n";
	}
}

void Bear::moveBy(int x, int y)
{
	dst.x += x * speed;
	dst.y += y * speed;
}

void Bear::boundsCheck()
{
	if (dst.x < 0)
		dst.x = 0;
	else if (dst.x > 150)
		dst.x = 150;
	if (dst.y < 0)
		dst.y = 0;
	else if (dst.y > 600 - dst.h)
		dst.y = 600 - dst.h;
}

Bear::Bear(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, int num_frames) : Sprite(renderer, filename, sizeX, sizeY, num_frames)
{
}

Bear::~Bear()
{
}
