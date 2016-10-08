//
//  AIChar.h
//  surviveTheWinter
//
//  Created by David Stuck on 1/11/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#ifndef __surviveTheWinter__AIChar__
#define __surviveTheWinter__AIChar__

#include <iostream>
#include "Char.h"
#include "AIMove.h"

class AIChar :
public Char
{
public:
    AIChar(float x, float y);
    ~AIChar();
    
    void Update(float elapsedTime);
    void ModHealth(float change, sf::Vector2f dir = sf::Vector2f(-1,-1));
	
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

#endif /* defined(__surviveTheWinter__AIChar__) */
