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

void Bullet::update(float deltaTime)
{
	dst.y -= deltaTime * speed;
	lifeTime -= deltaTime;

	if (lifeTime <= 0)
	{
		markedForRemoval = true;
	}
}

void Bullet::onCollisionWith(const Sprite& other)
{
	if (other.tag == OBSTACLE)
	{
		lifeTime = 0;
		markedForRemoval = true;

		Sprite* explosion = new Sprite(renderer, "Assets/explosion_01.png", 32, 32, 6);
		explosion->dst.x = dst.x;
		explosion->dst.y = dst.y;
		explosion->destroyOnAnimationComplete = true;

		spriteManager->add(explosion);
	}
}
