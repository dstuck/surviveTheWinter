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
#include "ActiveObject.h"
#include "AIMove.h"

class Char : public ActiveObject
{
public:
    Char(float, float, float, float, float att=0.0, float def=0.0);
    ~Char();
    virtual void Draw(sf::RenderWindow& rw);
    virtual bool GetAttacked(Char *);
    float GetHealth();
    float GetMaxHealth();

protected:
    void CharMove(sf::Vector2f);
    virtual void ModHealth(float);
    
//private:
    sf::Vector2f _danger_dir;
    float _health;
    float _maxHealth;
    float _att_val;
    float _def_val;
};


#endif /* defined(__surviveTheWinter__Char__) */