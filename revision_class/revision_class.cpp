#include <iostream>
#include <random>
#include <vector>
#include "Game.h"
#include "SFML/Graphics.hpp"


int test;

int main()
{
	Game game;

	//initialise the programm
	game.init();

	//loop of game play
	game.loop();
}
	
