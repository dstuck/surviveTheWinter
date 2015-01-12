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
#include "VisibleGameObject.h"
#include "AIMove.h"

class AIChar :
public VisibleGameObject
{
public:
	AIChar();
	~AIChar();
    
    void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);
	
    sf::Vector2f GetVelocity() const;
    
private:
    AIMove * GetNextMove();
    
    sf::Vector2f _velocity;
	float _maxSpeed;
    float _curSpeed;
    float _totalTime;
    float _decisionTime;
    AIMove * _curMove;
};

#endif /* defined(__surviveTheWinter__AIChar__) */
