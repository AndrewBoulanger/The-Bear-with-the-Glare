#include "Eye.h"
#include "SpriteManager.h"

Eye::Eye(SDL_Renderer* a_renderer, const char* filename, int sizeX, int sizeY, float a_speed) : Sprite(a_renderer, filename, sizeX, sizeY)
{
	tag = SpriteTag::ENEMY;
	speed = a_speed;
}

Eye::~Eye()
{
}



