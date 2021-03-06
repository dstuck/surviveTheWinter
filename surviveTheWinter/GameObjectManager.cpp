#include "stdafx.h"
#include "GameObjectManager.h"
#include "Game.h"
#include "Char.h"



GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	std::for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject)
{
	_gameObjects.insert(std::pair<std::string,VisibleGameObject*>(name, gameObject));
}

void GameObjectManager::Remove(std::string name)
{
	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	if(results != _gameObjects.end() )
	{
		delete results->second;
		_gameObjects.erase(results);
	}
}

VisibleGameObject* GameObjectManager::Get(std::string name) const
{
	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	if(results == _gameObjects.end() )
		return NULL;
	return results->second;
	
}

int GameObjectManager::GetObjectCount() const
{
	return int(_gameObjects.size());
}

std::map<std::string, VisibleGameObject*> GameObjectManager::GetMap() const {
    return _gameObjects;
}

void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
	std::map<std::string,VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	while(itr != _gameObjects.end())
	{
		itr->second->Draw(renderWindow);
		itr++;
	}
}

void GameObjectManager::UpdateAll(sf::Time timeDelta)
{
    std::map<std::string,VisibleGameObject*>::const_iterator itr =
    _gameObjects.begin();
    
    while(itr != _gameObjects.end())
    {
        itr->second->Update(timeDelta.asSeconds());
        itr++;
    }
}

void GameObjectManager::RemoveDead() {
//      Remove dead characters
    for(std::map<std::string,VisibleGameObject*>::const_iterator iter = _gameObjects.begin(); iter!=_gameObjects.end(); iter++) {
        //TODO(DES): Have VisibleGameObject have an is_dead command
        if(dynamic_cast<Char*>(iter->second)!=NULL) {
            if(dynamic_cast<Char*>(iter->second)->GetHealth()<=0) {
                delete iter->second;
                _gameObjects.erase(iter);
                return;
            }
        }
    }
}
