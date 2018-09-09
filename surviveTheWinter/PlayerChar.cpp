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

bool PlayerChar::PickUp(VisibleGameObject* carried) {
    if(carried->PickMeUp(this) & (_carried == NULL)) {
        _carried = carried;
        return true;
    }
    return false;
};

bool PlayerChar::PutDown() {
    bool dropped = _carried->PutMeDown(this);
    if (dropped) {
        _carried = NULL;
    }
    return dropped;
};

sf::Vector2f PlayerChar::CharMove(sf::Vector2f move) {
    if (_carried != NULL) {
        _isSolid = false;
        sf::Vector2f carried_move = dynamic_cast<Char*>(_carried)->CharMove(move);
        _isSolid = true;
        sf::Vector2f char_move = Char::CharMove(carried_move);
        dynamic_cast<Char*>(_carried)->CharMove(char_move - carried_move);
        return char_move;
    } else {
        return Char::CharMove(move);
    }
};

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
    
    if(_pickup_cool_time > 0.0) {
        _pickup_cool_time -= elapsedTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and (_pickup_cool_time <= 0.0)) {
        if (_carried != NULL) {
            PutDown();
            _pickup_cool_time += _pickup_delay;
        } else {
            for(auto vis_obj: Game::GetGameObjectManager().GetMap()) {
                if(IsTouching(*vis_obj.second, 20) and vis_obj.second!=this) {
                    PickUp(vis_obj.second);
                    _pickup_cool_time += _pickup_delay;
                }
            }
        }
    }
    
    if(_danger_dir != sf::Vector2f(0.f, 0.f)) {
        _velocity -= _danger_dir * _maxSpeed;
        _danger_dir = sf::Vector2f(0.f, 0.f);
    }
    
    CharMove(_velocity * elapsedTime);
}
