// Create and run the Game class
// Andrew Boulanger 101292574, Pauleen Lam 101065605, Rachel Medeiros 101170493
//with code from Joss and Ali
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

