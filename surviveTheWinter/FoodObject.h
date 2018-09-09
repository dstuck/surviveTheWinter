//
//  FoodObject.h
//  surviveTheWinter
//
//  Created by David Stück on 9/3/18.
//  Copyright © 2018 David Stuck. All rights reserved.
//

#ifndef FoodObject_h
#define FoodObject_h

#include "Carriable.hpp"
#include "Char.h"

class FoodObject : public Carriable< Char >
{
public:
    FoodObject(float x, float y);
    ~FoodObject();
    
protected:
    void CharMove(sf::Vector2f);
};


#endif /* FoodObject_h */
