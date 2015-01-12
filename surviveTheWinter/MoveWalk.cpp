//
//  MoveWalk.cpp
//  surviveTheWinter
//
//  Created by David Stuck on 1/11/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#include "MoveWalk.h"
#include "stdafx.h"

MoveWalk::MoveWalk(sf::Vector2f vec,float time):_walkVec(vec),_walkTime(time) {
    
}

MoveWalk::~MoveWalk() {
    
}

sf::Vector2f MoveWalk::GetVelocity() {
    return _walkVec;
}

float MoveWalk::GetTime() {
    return _walkTime;
}

void MoveWalk::PrintMove() {
    std::cout << "Move ("<<_walkVec.x <<","<<_walkVec.y<<") for "<<_walkTime<<" seconds"<<std::endl;
}