// Create and run the Game class
// Joss Moo-Young
#include <iostream>
#include"Game.h"

Game myGame;

// Main function.
int main(int argc, char* args[]) // Main MUST have these parameters for SDL.
{
	myGame = Game("The Bear with the Glare", 800, 600);
	myGame.run();
	return 0;
}

// fix bugs - done
// animation - done-ish... added bugs!
// ship class - done!
// multiple projectiles - done!
// collision management so that projectiles can hit the asteroid - done
// continuous movement -...
