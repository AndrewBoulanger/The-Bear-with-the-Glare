#pragma once
#include<SDL_image.h>
#include "SpriteTags.h"

class SpriteManager;

// Sprite class which contains a texture, position, velocity, size, and functions for drawing it.

int distanceSq(int x1, int y1, int x2, int y2);

class Sprite
{
protected:
	SDL_Renderer* renderer;
	SDL_Texture* pSpriteTex = nullptr;
	SDL_Rect src; // where in the texture to draw from
	float speed = 4;
	SDL_Rect* target;
	int health;

public:
	SpriteManager* spriteManager;
	SDL_Rect dst; // where in the screen to draw to

	// an identifier for what kind of object this sprite is
	SpriteTag tag = SpriteTag::NONE;

	// hey! i'm ready to be removed from the spriteManager!
	bool markedForRemoval = false;

	// animation fields
	int frameCount;
	int currentFrame;
	bool loopAnimation = true;
	bool playAnimation = true;
	bool destroyOnAnimationComplete = false;
	int damageCooldown = 0;

	int points = 0;

	// constructors -- these are used when initializing an object
	Sprite();
	Sprite(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY, int num_frames = 1);
	
	// destructor -- used when the object is to be removed from memory
	~Sprite();

	void setPosition(int x, int y);
	void setSize(int x, int y);
	void setSourceSize(int x, int y);
	void draw();
	void drawMultiple(int times);
	virtual void update(float deltaTime);
	void updateAnimation(); // update the animation state 
	void setFrame(int frame);
	void moveBackground(int scrollSpeed);

	bool isCollidingWith(const Sprite &other);
	bool isCollidingCircular(const Sprite& other);
	virtual void onCollisionWith(const Sprite& other);

	void setTarget(SDL_Rect* a_target)
	{
		target = a_target;
	}

	void cleanup();
};

