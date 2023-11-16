#include "Ball.h"
#include <SFML/Graphics.hpp>
#include <random>

Ball::Ball(sf::Vector2u size)
{
	//can go to ball
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<float> rnd_radius(0, 300);

	float gen_radius = std::floorf(rnd_radius(eng));
	std::uniform_real_distribution<float> rnd_x(gen_radius, size.x - gen_radius);
	std::uniform_real_distribution<float> rnd_y(gen_radius, size.y - gen_radius);

	float x = rnd_x(eng);
	float y = rnd_y(eng);

	ball_shape_ = sf::CircleShape(gen_radius, 64);

	ball_shape_.setOrigin(gen_radius, gen_radius);
	ball_shape_.setPosition(x, y);
	ball_shape_.setFillColor(orange_);
	ball_shape_.setOutlineColor(white_);
	ball_shape_.setOutlineThickness(1);
}

void Ball::FadeOut()
{
	const float fade_ratio_ = 0.95f;

	sf::Color current_color = ball_shape_.getFillColor();
	current_color.a *= fade_ratio_;
	ball_shape_.setFillColor(current_color);

}
