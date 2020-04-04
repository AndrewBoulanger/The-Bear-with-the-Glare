#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* a_renderer, const char* filename, int sizeX, int sizeY) : Sprite(renderer, filename, sizeX, sizeY)
{
	tag = SpriteTag::ENEMY;
}

Enemy::~Enemy()
{
}