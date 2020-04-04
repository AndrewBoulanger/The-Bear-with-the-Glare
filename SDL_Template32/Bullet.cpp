#include "Bullet.h"
#include "SpriteManager.h"


Bullet::Bullet()
{
}

Bullet::Bullet(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, float a_speed) : Sprite(renderer, filename, sizeX, sizeY)
{
	speed = a_speed;
	tag = SpriteTag::PROJECTILE;
}
Bullet::Bullet(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, float a_speed, float targX, float targY) : Sprite(renderer, filename, sizeX, sizeY)
{
	speed = a_speed;
	tag = SpriteTag::OBSTACLE;
	dirX = targX;
	dirY = targY;

}


void Bullet::update(float deltaTime)
{
	dst.x += deltaTime * speed * dirX;
	dst.y += deltaTime * speed * dirY;
	lifeTime -= deltaTime;

	if (lifeTime <= 0)
	{
		markedForRemoval = true;
	}
}

void Bullet::onCollisionWith(const Sprite& other)
{
	if (other.tag == ENEMY && tag != ENEMY )
	{
		lifeTime = 0;
		markedForRemoval = true;

		Sprite* explosion = new Sprite(renderer, "Assets/explosion_01.png", 32, 32, 6);
		explosion->dst.x = dst.x;
		explosion->dst.y = dst.y -16;
		explosion->destroyOnAnimationComplete = true;
		
		spriteManager->add(explosion);
	}
}
