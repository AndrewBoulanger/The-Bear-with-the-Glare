#include "Eye.h"
#include "SpriteManager.h"


Eye::Eye(SDL_Renderer* a_renderer, const char* filename, int sizeX, int sizeY, float a_speed) : Sprite(a_renderer, filename, sizeX, sizeY)
{
	tag = SpriteTag::ENEMY;
	speed = a_speed;
	health = 3;
}

Eye::~Eye()
{
}

void Eye::shoot()
{
	if (shootTimer <= 0)
	{
		// shoot
		Bullet* b = new Bullet(renderer, "Assets/laserRed01.png", 25, 10, 200,target->x+target->w/2-dst.x, target->y +target->h/2 -dst.y);
		b->dst.x = dst.x - dst.w * 0.6;
		b->dst.y = dst.y + (dst.h * 0.33);

		spriteManager->add(b);
		shootTimer = shootInterval;
	}
}

void Eye::update(float deltaTime)
{
	counter+=1;
	velocity = speed * deltaTime;
	acceleration = 3 * sin(counter / interval) * velocity;
	dst.x -=velocity + acceleration;

	damageCooldown -= deltaTime;
	if (damageCooldown < 0) damageCooldown = 0;

	shootTimer -= deltaTime;
	if (shootTimer < 0) shoot();

	if (dst.x <= 0 - dst.w)
		markedForRemoval = true;
	
}

void Eye::onCollisionWith(const Sprite& other)
{
	if (other.tag == PROJECTILE && damageCooldown <= 0)
	{
		health--;
		damageCooldown = 10;
		if (health <= 0) 
		{
			points = 10;
			markedForRemoval = true;
		}
	}

}