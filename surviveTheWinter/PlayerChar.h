#pragma once
#include "Char.h"

class PlayerChar :
public Char
{
public:
	PlayerChar(float, float);
	~PlayerChar();
    
    sf::Vector2f CharMove(sf::Vector2f move);
    void Update(float elapsedTime);
    bool PickUp(VisibleGameObject* carried);
    bool PutDown();
	
    sf::Vector2f GetVelocity() const;
    
private:
    VisibleGameObject* _carried = NULL;
    sf::Vector2f _velocity;
    float _maxSpeed;
    float _curSpeed;
    float _pickup_delay = 0.5;
    float _pickup_cool_time = 0.;
};
