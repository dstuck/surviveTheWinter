//
//  VectorUtil.h
//  surviveTheWinter
//
//  Created by David Stuck on 1/11/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#ifndef __surviveTheWinter__VectorUtil__
#define __surviveTheWinter__VectorUtil__

#include <iostream>
#include "stdafx.h"

namespace VectorUtil {
    float VDist(sf::Vector2f,sf::Vector2f);
    float VNorm(sf::Vector2f);
    void VNormalize(sf::Vector2f&,float = 0.00001);
    void VScale(sf::Vector2f&, float);
}


#endif /* defined(__surviveTheWinter__VectorUtil__) */
