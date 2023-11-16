#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
	sf::CircleShape ball_shape_;

	 sf::Color orange_ = sf::Color(235, 152, 9);
	 sf::Color white_ = sf::Color::White;

public:
	Ball(sf::Vector2u size);
	void FadeOut();

	sf::CircleShape GetShape() { return ball_shape_; }
	sf::Color GetColor() { return ball_shape_.getFillColor(); }
	sf::Vector2f GetPosition() { return ball_shape_.getPosition(); }
	float GetRadius() { return ball_shape_.getRadius(); }
	void SetRadius(const float radius) { ball_shape_.setRadius(radius); }
	void SetOrigin(const float x, const float y) { ball_shape_.setOrigin(x, y); }
};
