//
//  EnemyChar.h
//  surviveTheWinter
//
//  Created by David Stuck on 1/12/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#ifndef __surviveTheWinter__EnemyChar__
#define __surviveTheWinter__EnemyChar__


#include <iostream>
#include "Char.h"
#include "AIMove.h"

class EnemyChar :
public Char
{
public:
	EnemyChar();
	~EnemyChar();
    
    void Update(float elapsedTime);
//	void Draw(sf::RenderWindow& rw);
//    void ModHealth(float);
	
    sf::Vector2f GetVelocity() const;
    
private:
    AIMove * GetNextMove();
    
    sf::Vector2f _velocity;
	float _maxSpeed;
    float _curSpeed;
    float _totalTime;
    float _decisionTime;
//    float _health;
//    float _maxHealth;
    AIMove * _curMove;
};

#endif /* defined(__surviveTheWinter__EnemyChar__) */
