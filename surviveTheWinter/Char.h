//
//  Char.h
//  surviveTheWinter
//
//  Created by David Stuck on 1/13/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#ifndef __surviveTheWinter__Char__
#define __surviveTheWinter__Char__

#include <iostream>
#include "VisibleGameObject.h"
#include "AIMove.h"

class Char : public VisibleGameObject
{
public:
    Char(float, float, float, float);
    ~Char();
    virtual void Draw(sf::RenderWindow& rw);
    virtual void ModHealth(float);
    float GetHealth();
    float GetMaxHealth();

protected:
    void CharMove(sf::Vector2f);
    float _health;
    float _maxHealth;
};


#endif /* defined(__surviveTheWinter__Char__) */
