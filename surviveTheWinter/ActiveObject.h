//
//  ActiveObject.h
//  surviveTheWinter
//
//  Created by David Stuck on 10/9/16.
//  Copyright (c) 2016 David Stuck. All rights reserved.
//

#ifndef __surviveTheWinter__ActiveObject__
#define __surviveTheWinter__ActiveObject__

#include <stdio.h>
#include "VisibleGameObject.h"

class Char;

class ActiveObject : public VisibleGameObject
{
public:
    ActiveObject(float, float, bool);
    ~ActiveObject();
    virtual bool GetAttacked(Char *);
    
protected:
};

#endif /* defined(__surviveTheWinter__ActiveObject__) */
