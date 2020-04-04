#pragma once
#include "Sprite.h"

class Enemy : public Sprite
{
public:
	Enemy(SDL_Renderer* a_renderer, const char* filename, int sizeX, int sizeY, float a_speed);
	~Enemy();

};