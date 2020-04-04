#pragma once
#include "Sprite.h"

class Eye : public Sprite
{
public:
	Eye(SDL_Renderer* a_renderer, const char* filename, int sizeX, int sizeY, float a_speed);
	~Eye();

	void update(float deltaTime) override;
	void onCollisionWith(const Sprite& other) override;
	
};