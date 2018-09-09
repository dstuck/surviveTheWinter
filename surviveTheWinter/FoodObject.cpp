//
//  FoodObject.cpp
//  surviveTheWinter
//
//  Created by David Stück on 9/3/18.
//  Copyright © 2018 David Stuck. All rights reserved.
//

#include "FoodObject.h"

#include "Game.h"

FoodObject::FoodObject(float x, float y)
    : Char(100, 100, x, y, true)
{
    Load(resourcePath() + "apple.jpg");
    assert(IsLoaded());
    
    GetSprite().setOrigin(GetSprite().getGlobalBounds().width/2, GetSprite().getGlobalBounds().height/2);
}

FoodObject::~FoodObject()
{
}
