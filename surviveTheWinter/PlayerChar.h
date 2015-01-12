#pragma once
#include "VisibleGameObject.h"

class PlayerChar :
public VisibleGameObject
{
public:
	PlayerChar();
	~PlayerChar();
    
    void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);
	
    sf::Vector2f GetVelocity() const;
    
private:
    sf::Vector2f _velocity;
	float _maxSpeed;
    float _curSpeed;
};