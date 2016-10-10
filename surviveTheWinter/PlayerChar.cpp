#include "stdafx.h"
#include "PlayerChar.h"
#include "Game.h"
#include "VectorUtil.h"


PlayerChar::PlayerChar(float x, float y) : _velocity(0.0,0.0), _maxSpeed(600.0f),
                                           _curSpeed(600.0f),
                                           Char(100.0,100.0, x, y)
{
	Load(resourcePath() + "player.jpg");
	assert(IsLoaded());
    
	GetSprite().setOrigin(GetSprite().getGlobalBounds().width/2, GetSprite().getGlobalBounds().height/2);
    
}

PlayerChar::~PlayerChar()
{
}


sf::Vector2f PlayerChar::GetVelocity() const
{
	return _velocity;
}

void PlayerChar::Update(float elapsedTime)
{
    _velocity.x = 0.0;
    _velocity.y = 0.0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_velocity.x -= _curSpeed;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_velocity.x += _curSpeed;
	}
    
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_velocity.y += _curSpeed;
	}
    
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_velocity.y -= _curSpeed;
	}
    
//	if(_velocity > _maxSpeed)
//		_velocity = _maxSpeed;
//    
//	if(_velocity < -_maxSpeed)
//		_velocity = -_maxSpeed;
//    
//	sf::Vector2f pos = this->GetPosition();
//    
//	if(pos.x  < GetSprite().getGlobalBounds().width/2 && _velocity.x < 0) {
//        _velocity.x = 0; // Stop at bound
//    }
//    if(pos.x > (Game::SCREEN_WIDTH - GetSprite().getGlobalBounds().width/2) && _velocity.x > 0) {
//		_velocity.x = 0; // Stop at bound
//	}
//    
//	if(pos.y  < GetSprite().getGlobalBounds().height/2 && _velocity.y < 0) {
//        _velocity.y = 0; // Stop at bound
//	}
//    if(pos.y > (Game::SCREEN_HEIGHT - GetSprite().getGlobalBounds().height/2) && _velocity.y > 0) {
//		_velocity.y = 0; // Stop at bound
//	}
//  Normalize _velocity
//    if(_velocity.x !=0 && _velocity.y !=0) {
//        _velocity.x /= 1.41421356;
//        _velocity.y /= 1.41421356;
//    }
    
//    std::cout<<"Player velocity is ("<<_velocity.x<<","<<_velocity.y<<")"<<std::endl;
    
//	ModHealth(-1*elapsedTime);
//	GetSprite().move(_velocity * elapsedTime);
    CharMove(_velocity * elapsedTime);
}
