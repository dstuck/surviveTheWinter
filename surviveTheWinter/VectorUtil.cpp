//
//  VectorUtil.cpp
//  surviveTheWinter
//
//  Created by David Stuck on 1/11/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#include "VectorUtil.h"
#include <cmath>

float VectorUtil::VDist(sf::Vector2f v1,sf::Vector2f v2) {
    return VNorm(v1-v2);
}
float VectorUtil::VNorm(sf::Vector2f v1) {
    float norm = (v1.x)*(v1.x);
    norm += (v1.y)*(v1.y);
    norm = sqrt(norm);
    return norm;
}

void VectorUtil::VNormalize(sf::Vector2f& v1, float thresh) {
    float norm = VNorm(v1);
    if(norm>thresh) {
        v1.x /= norm;
        v1.y /= norm;
    }
}

void VectorUtil::VScale(sf::Vector2f& v1, float scale) {
    v1.x*=scale;
    v1.y*=scale;
}