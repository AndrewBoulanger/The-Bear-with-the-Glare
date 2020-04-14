#include "SpriteManager.h"
#include <algorithm>
#include <iostream>

SpriteManager::SpriteManager()
{
}

SpriteManager::~SpriteManager()
{
}

void SpriteManager::cleanup()
{
	for (int i = 0; i < sprites.size(); i++)
	{
		
		sprites[i]->cleanup();
		delete sprites[i];
	}
}

void SpriteManager::updateAll(float deltaTime)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i] != nullptr)
		{
			sprites[i]->update(deltaTime);
		}
	}

	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i]->markedForRemoval)
		{
			score += sprites[i]->points;
			sprites[i]->cleanup();
			delete sprites[i];
			sprites[i] = nullptr;
		}
	}

	auto endPos = std::remove(sprites.begin(), sprites.end(), nullptr);
	sprites.erase(endPos, sprites.end());

	// check for collision between every sprite and every other sprite
	for (int i = 0; i < sprites.size(); i++)
	{//i is the first sprite

		for (int j = i + 1; j < sprites.size(); j++)
		{ // j is the second sprite

			if (sprites[i]->isCollidingCircular(*sprites[j]))
			{
				sprites[i]->onCollisionWith(*sprites[j]);
				sprites[j]->onCollisionWith(*sprites[i]);
			}
		}
	}
}

void SpriteManager::drawAll()
{
	for (int i = 0; i < sprites.size(); i++)
	{
		sprites[i]->draw();
		sprites[i]->updateAnimation();
	}
}

void SpriteManager::add(Sprite* spriteToAdd)
{
	sprites.push_back(spriteToAdd);
	spriteToAdd->spriteManager = this;
}

