#include "Eye.h"
#include "SpriteManager.h"
#include <time.h>

Eye::Eye(SDL_Renderer* a_renderer, const char* filename, int sizeX, int sizeY, float a_speed) : Sprite(a_renderer, filename, sizeX, sizeY)
{
	tag = SpriteTag::ENEMY;
	speed = a_speed;
	health = 5;
}

Eye::~Eye()
{
}

void Eye::update(float deltaTime)
{
	dst.x -= speed * deltaTime;
	//oh my god, setting their speed to a sin pattern is terrifying. I love it
	speed +=  2* sin(time(0));
}

void Eye::onCollisionWith(const Sprite& other)
{
	if (other.tag == PROJECTILE)
	{
		health--;
		if(health <= 0)
			markedForRemoval = true;
	}

}