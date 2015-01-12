#include "stdafx.h"
#include "SplashScreen.h"
#include "ResourcePath.hpp"


void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
	sf::Texture image;
//    std::cout << "Before load file" << std::endl;
	if(image.loadFromFile(resourcePath()+ "SplashScreen.png") != true)
	{
		return;
	}
//    image.loadFromFile(resourcePath()+ "MainMenu.png");
//    std::cout << "Before sprite" << std::endl;
	sf::Sprite sprite(image);
//    std::cout << "Before sprite" << std::endl;
	renderWindow.draw(sprite);
	renderWindow.display();
    
	sf::Event event;
	while(true)
	{
		while(renderWindow.pollEvent(event))
		{
			if(event.type == sf::Event::EventType::KeyPressed
               || event.type == sf::Event::EventType::MouseButtonPressed
               || event.type == sf::Event::EventType::Closed )
			{
				return;
			}
		}
	}
}