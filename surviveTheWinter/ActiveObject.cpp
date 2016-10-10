//
//  ActiveObject.cpp
//  surviveTheWinter
//
//  Created by David Stuck on 10/9/16.
//  Copyright (c) 2016 David Stuck. All rights reserved.
//

#include "Char.h"
#include "ActiveObject.h"

ActiveObject::ActiveObject(float x, float y) {
    SetPosition(x, y);
}

ActiveObject::~ActiveObject() {
    
}

bool ActiveObject::GetAttacked(Char *attacker) {
    return false;
}