#pragma once
#include <SFML/Graphics.hpp>

#include "Ball.h"


class Game
{
	sf::RenderWindow window_;

	std::vector<sf::CircleShape> balls_;
	std::vector<Ball> balls_objects_;

	sf::Clock clock_;

	float fade_ratio_ = 0.95f;

	bool game_over_ = false;

	const sf::Color orange_ = sf::Color(235, 152, 9);
	const sf::Color white_ = sf::Color::White;



public:
	void init();
	void GraphicalFrame();
	void Event(sf::Event event);
	void SpawnABall();
	int loop();
};
