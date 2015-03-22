#include "stdafx.h"
#include "Game.h"
#include "Char.h"


void Game::Start(void)
{
    if(_gameState != Uninitialized)
        return;
    
    _mainWindow.create(sf::VideoMode(1024,768,32),"Pang!");
    _mainWindow.setKeyRepeatEnabled(false);
    
	PlayerChar *player1 = new PlayerChar();
    AIChar *ai1 = new AIChar();
    EnemyChar *enemy1 = new EnemyChar();
	player1->SetPosition((1024/2),(768/2));
	ai1->SetPosition((1024*.75),(768*.2));
    enemy1->SetPosition(100,100);
	
	_gameObjectManager.Add("Player1",player1);
    _gameObjectManager.Add("AI1",ai1);
    _gameObjectManager.Add("enemy1",enemy1);
    _gameState= Game::ShowingSplash;
    
    while(!IsExiting())
    {
        GameLoop();
    }
    
    _mainWindow.close();
}

void Game::ExitGame() {
    _gameState = Game::Exiting;
}

bool Game::IsExiting()
{
    if(_gameState == Game::Exiting)
        return true;
    else
        return false;
}

sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

//const sf::input& Game::GetInput()
//{
//	return _mainWindow.GetInput();
//}

void Game::GameLoop()
{
    sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
    
	switch(_gameState)
	{
		case Game::ShowingMenu:
        {
            ShowMenu();
            _clock.restart();
            break;
        }
		case Game::ShowingSplash:
        {
            ShowSplashScreen();
//            _gameState = Game::ShowingMenu;
            break;
        }
		case Game::Playing:
        {
            _mainWindow.clear(sf::Color(0,0,0));
            
            sf::Time elapsed = _clock.restart();

            _gameObjectManager.UpdateAll(elapsed);
            _gameObjectManager.DrawAll(_mainWindow);
            
            _mainWindow.display();
            
            if(currentEvent.type == sf::Event::Closed) {
                std::cout<<"Exiting"<<std::endl;
                _gameState = Game::Exiting;
            }
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                //ResetGame();
                ShowMenu();
            }
//                if(currentEvent.type == sf::Event::KeyPressed)
//                {
//                    if(currentEvent.key.code == sf::Keyboard::Escape) {
////                        std::cout << "Escape key pressed!" << std::endl;
//                        ShowMenu();
//                    }
//                }
            _gameObjectManager.RemoveDead();

            break;
        }
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch(result)
	{
        case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
	}
}

const GameObjectManager& Game::GetGameObjectManager()
{
	return _gameObjectManager;
}

sf::Clock Game::_clock;
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;