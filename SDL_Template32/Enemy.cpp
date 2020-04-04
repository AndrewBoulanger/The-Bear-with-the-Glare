#include "Enemy.h"
#include "SpriteManager.h"

Enemy::Enemy(SDL_Renderer* a_renderer, const char* filename, int sizeX, int sizeY, float a_speed) : Sprite(a_renderer, filename, sizeX, sizeY)
{
	tag = SpriteTag::ENEMY;
	speed = a_speed;
}

Enemy::~Enemy()
{
}


