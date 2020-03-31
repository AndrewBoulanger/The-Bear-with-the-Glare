#pragma once
#include <vector>
#include "Sprite.h"

class SpriteManager
{
private:
	std::vector<Sprite*> sprites;

public:
	SpriteManager();
	~SpriteManager();


	void cleanup();
	void updateAll(float deltaTime);
	void drawAll();

	void add(Sprite* spriteToAdd);
};

