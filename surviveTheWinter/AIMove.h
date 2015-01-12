//
//  AIMove.h
//  surviveTheWinter
//
//  Created by David Stuck on 1/11/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#ifndef __surviveTheWinter__AIMove__
#define __surviveTheWinter__AIMove__

#include <iostream>
#include "stdafx.h"


class AIMove {
public:
    AIMove();
    ~AIMove();
    
    virtual sf::Vector2f GetVelocity();
    virtual float GetTime();
    virtual void PrintMove();
};

#endif /* defined(__surviveTheWinter__AIMove__) */
