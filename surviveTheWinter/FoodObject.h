//
//  FoodObject.h
//  surviveTheWinter
//
//  Created by David Stück on 9/3/18.
//  Copyright © 2018 David Stuck. All rights reserved.
//

#ifndef FoodObject_h
#define FoodObject_h

#include "VisibleGameObject.h"

class FoodObject : public VisibleGameObject
{
public:
    FoodObject(float, float);
    ~FoodObject();
    
protected:
    void CharMove(sf::Vector2f);

private:
    float _health;
    float _maxHealth;
    float _att_val;
    float _def_val;
};


#endif /* FoodObject_h */
