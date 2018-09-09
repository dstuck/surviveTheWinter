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
    Char(float=0, float=0, float=0, float=0, float att=0.0, float def=0.0);
    ~Char();
    virtual void Draw(sf::RenderWindow& rw);
    virtual bool GetAttacked(Char *);
    float GetHealth();
    float GetMaxHealth();
    sf::Vector2f CharMove(sf::Vector2f);

protected:
    virtual void ModHealth(float);

    sf::Vector2f _danger_dir;
private:
    float _health = 0;
    float _maxHealth = 0;
    float _att_val = 0;
    float _def_val = 0;
};


#endif /* defined(__surviveTheWinter__Char__) */
