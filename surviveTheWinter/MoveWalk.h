//
//  MoveWalk.h
//  surviveTheWinter
//
//  Created by David Stuck on 1/11/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#ifndef __surviveTheWinter__MoveWalk__
#define __surviveTheWinter__MoveWalk__

#include <iostream>
#include "AIMove.h"

class MoveWalk:
public AIMove {
public:
    MoveWalk(sf::Vector2f,float);
    ~MoveWalk();
    
    sf::Vector2f GetVelocity();
    float GetTime();
    void PrintMove();

private:
    sf::Vector2f _walkVec;
    float _walkTime;
    
};

#endif /* defined(__surviveTheWinter__MoveWalk__) */
