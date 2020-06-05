#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGl.hpp>

class Game
{
	private:

		sf::Vector2f wb;
		
		//variables;
		sf::RenderWindow* window;
		sf::Event sfEvent;

		sf::VideoMode window_bounds;
		sf::Clock dtClock;
		float dt;

		sf::RectangleShape tm;
		sf::RectangleShape pb;
		sf::RectangleShape pa;
		sf::RectangleShape pg;

		sf::Texture tmt;
		sf::Texture pbt;
		sf::Texture pat;
		sf::Texture pgt;



		//initialization
		void initWindow();
		


	public:
		//Constructors/Destructors
		Game();
	    virtual ~Game();
		//Functions
		void updatedt();
		void updateSFMLEvents();
		void update();


		//Init sprites
		void is();

		//Render
		void render();
		void rp(sf::Vector2f);


		void run();
		

		
		
};
#endif

