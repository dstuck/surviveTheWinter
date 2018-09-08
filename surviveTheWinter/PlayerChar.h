#pragma once
#include "Carriable.hpp"
#include "Char.h"

class PlayerChar :
public Char
{
public:
	PlayerChar(float, float);
	~PlayerChar();
    
    void Update(float elapsedTime);
	
    sf::Vector2f GetVelocity() const;
    
private:
    sf::Vector2f _velocity;
    float _maxSpeed;
    float _curSpeed;
};
