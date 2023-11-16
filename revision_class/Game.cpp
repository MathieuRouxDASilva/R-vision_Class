#include "Game.h"
#include <iostream>
#include <random>



float cool_down = 3.0f;
constexpr float kCoolDownDecrease = 0.2f;


void Game::init()
{
	window_.create(sf::VideoMode(800, 600), "The Game");

	// Basic Setup of the window
	// Vertical sync, framerate
	window_.setVerticalSyncEnabled(true);
	window_.setFramerateLimit(30);
}

void Game::GraphicalFrame()
{
	// Graphical Region
	window_.clear(sf::Color::Black);


	for (auto& b : balls_objects_)
	{
		b.FadeOut();

		if (b.GetColor().a <= 1)
		{
			// Game Over ----------------------------------------------
			game_over_ = true;
		}

		window_.draw(b.GetShape());
	}



	// Window Display
	window_.display();
}

void Game::Event(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonReleased:
		{
			sf::Vector2f mousePos = { (float)event.mouseButton.x, (float)event.mouseButton.y };


			//try factoristion
			for (auto ball_object_it = balls_objects_.begin(); ball_object_it != balls_objects_.end(); ++ball_object_it)
			{
				//sf::Vector2f mem_position = b.getPosition();
				sf::Vector2f diste = ball_object_it->GetPosition() - mousePos;
				//calcul pour comprendre si le click est dans le 
				if (std::sqrt(diste.x * diste.x + diste.y * diste.y) < ball_object_it->GetRadius())
				{
					ball_object_it->SetRadius(ball_object_it->GetRadius() / 2);
					ball_object_it->SetOrigin(ball_object_it->GetRadius(), ball_object_it->GetRadius());

					//erase and ball apear faster
					if (ball_object_it->GetRadius() < 8)
					{
						balls_objects_.erase(ball_object_it);
						cool_down -= kCoolDownDecrease;
					}

					break;
				}
			}
		}
		break;

	// évènement "fermeture demandée" : on ferme la fenêtre
	case sf::Event::Closed:
		window_.close();
		break;

	case sf::Event::Resized:
		window_.close();
		break;

	default:
		break;
	}
}

void Game::SpawnABall()
{
	if (clock_.getElapsedTime().asSeconds() > cool_down) //délais de formation du rond
	{

		clock_.restart();

		balls_objects_.emplace_back(window_.getSize());
	}
}

//loop of the game
int Game::loop()
{
	while (window_.isOpen())
	{
		if (game_over_)
		{
			std::cout << "=== === === === === === === GAME OVER === === === === === === ===" << std::endl;
			continue;
		}


		SpawnABall();

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		while (window_.pollEvent(event))
		{
			Event(event);
		}

		GraphicalFrame();
	}
	return EXIT_SUCCESS;
}


