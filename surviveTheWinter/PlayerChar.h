#pragma once
//#include "VisibleGameObject.h"
#include "Char.h"

class PlayerChar :
public Char
{
public:
	PlayerChar(float, float);
	~PlayerChar();
    
    void Update(float elapsedTime);
//    float GetHealth();
//    void ModHealth(float);
	
    sf::Vector2f GetVelocity() const;
    
private:
    sf::Vector2f _velocity;
    float _maxSpeed;
    float _curSpeed;
//    float _health;
//    float _maxHealth;
};
