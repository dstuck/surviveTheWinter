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
#include "VisibleGameObject.h"

class FoodObject : public Carriable< VisibleGameObject >
{
public:
    FoodObject(float, float);
    ~FoodObject();
    
protected:
    void CharMove(sf::Vector2f);

};


#endif /* FoodObject_h */
