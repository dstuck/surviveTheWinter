//
//  Game.h
//  surviveTheWinter
//
//  Created by David Stuck on 1/10/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#pragma once
#include "ResourcePath.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "PlayerChar.h"
#include "AIChar.h"
#include "EnemyChar.h"
#include "FoodObject.h"
#include "GameObjectManager.h"




class Game
{
public:
	static void Start();
    static sf::RenderWindow& GetWindow();
//	const static sf::input& GetInput();
    static void ExitGame();
    const static GameObjectManager& GetGameObjectManager();
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

    
private:
	static bool IsExiting();
	static void GameLoop();
	
	static void ShowSplashScreen();
	static void ShowMenu();
    
	enum GameState { Uninitialized, ShowingSplash, Paused,
        ShowingMenu, Playing, Exiting };
    
	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
//    static PlayerChar _player1;
    
    static sf::Clock _clock;
	static GameObjectManager _gameObjectManager;

};

