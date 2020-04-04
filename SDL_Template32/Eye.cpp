#include "Eye.h"
#include "SpriteManager.h"


Eye::Eye(SDL_Renderer* a_renderer, const char* filename, int sizeX, int sizeY, float a_speed) : Sprite(a_renderer, filename, sizeX, sizeY)
{
	tag = SpriteTag::ENEMY;
	speed = a_speed;
	health = 5;
}

Eye::~Eye()
{
}

void Eye::shoot()
{
	if (shootTimer <= 0)
	{
		// shoot
		Bullet* b = new Bullet(renderer, "Assets/laserRed01.png", 25, 10, 200,target->x-dst.x, target->y -dst.y);
		b->dst.x = dst.x - dst.w * 0.6;
		b->dst.y = dst.y + (dst.h * 0.33);

		spriteManager->add(b);
		shootTimer = shootInterval;
	}
}

void Eye::update(float deltaTime)
{
	dst.x -= speed * deltaTime;
	//oh my god, setting their speed to a sin pattern is terrifying. I love it
	speed +=  2* sin(time(0));

	damageCooldown -= deltaTime;
	if (damageCooldown < 0) damageCooldown = 0;

	shootTimer -= deltaTime;
	if (shootTimer < 0) shoot();
	
}

void Eye::onCollisionWith(const Sprite& other)
{
	if (other.tag == PROJECTILE && damageCooldown <= 0)
	{
		health--;
		damageCooldown = 10;
		if(health <= 0)
			markedForRemoval = true;
	}

}