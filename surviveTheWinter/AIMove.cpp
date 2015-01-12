//
//  AIMove.cpp
//  surviveTheWinter
//
//  Created by David Stuck on 1/11/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#include "AIMove.h"
AIMove::AIMove() {
    
}

AIMove::~AIMove() {
    
}

sf::Vector2f AIMove::GetVelocity() {
    sf::Vector2f vel(0.0,0.0);
    return vel;
}

float AIMove::GetTime() {
    return 0.1;
}

void AIMove::PrintMove() {
    std::cout << "Unspecified move."<<std::endl;
}