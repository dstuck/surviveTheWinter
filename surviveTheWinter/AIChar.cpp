//
//  AIChar.cpp
//  surviveTheWinter
//
//  Created by David Stuck on 1/11/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#include "stdafx.h"
#include "AIChar.h"
#include "Game.h"
#include "MoveWalk.h"
#include "VectorUtil.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>


AIChar::AIChar():
_totalTime(0.0),
_velocity(0.0,0.0),
_maxSpeed(400.0f),
_curSpeed(400.0f)
{
    sf::Vector2f zeroV(0,0);
    _curMove = new MoveWalk(zeroV,1);
    _decisionTime = _curMove->GetTime();
	Load(resourcePath() + "monster.jpg");
	assert(IsLoaded());
    srand (time(NULL));
    
	GetSprite().setOrigin(GetSprite().getGlobalBounds().width/2, GetSprite().getGlobalBounds().height/2);
    
}

AIChar::~AIChar()
{
}

void AIChar::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}

sf::Vector2f AIChar::GetVelocity() const
{
	return _velocity;
}

AIMove * AIChar::GetNextMove() {
    if(_curMove!=NULL){
        delete _curMove;
    }
    
    double timeStep = .3;
    double timeRange = 0.3;
    double timeMid = 0.4;
    double tooClose = 300.0;
    int speedRange = 200;
    sf::Vector2f bias(0,0);
    
    PlayerChar* thePlayer = dynamic_cast<PlayerChar*>(Game::GetGameObjectManager().Get("Player1"));
    sf::Vector2f pVec = thePlayer->GetPosition();
    float pDist = VectorUtil::VDist(pVec, GetPosition());
    
    if(pDist<tooClose) {
        bias = GetPosition()-pVec;
        VectorUtil::VNormalize(bias);
        VectorUtil::VScale(bias,float(speedRange)/1.5);
        timeMid = .8;
//        timeStep = float(rand())/RAND_MAX*timeRange/2+timeMid;
    }
    else {
        bias = pVec-GetPosition();
        VectorUtil::VNormalize(bias);
        VectorUtil::VScale(bias,float(speedRange)/4.0);
    }
    
    sf::Vector2f moveVec(rand()%(2*speedRange)-speedRange+bias.x,rand()%(2*speedRange)-speedRange+bias.y);
    MoveWalk * nMove = new MoveWalk(moveVec,float(rand())/RAND_MAX*timeRange/2+timeMid);
    return nMove;
}

void AIChar::Update(float elapsedTime)
{
    _totalTime += elapsedTime;
//    std::cout << "elapsedTime = "<<elapsedTime << std::endl;
    _decisionTime -= elapsedTime;
//    std::cout << "decisionTime = "<< _decisionTime << std::endl;
    if(_decisionTime <= 0.0) {
        _curMove = GetNextMove();
        _decisionTime = _curMove->GetTime();
    }
    _velocity = _curMove->GetVelocity();
    
//    _curMove->PrintMove();
    
    //  Normalize _velocity
//    if(_velocity.x !=0 && _velocity.y !=0) {
//        double norm = VectorUtil::VNorm(_velocity);
//        _velocity.x /= norm;
//        _velocity.y /= norm;
//        _velocity *= _curSpeed;
//    }
//    VectorUtil::VNormalize(_velocity);
//    _velocity *= _curSpeed;
	
    sf::Vector2f pos = this->GetPosition();
    
	if(pos.x  < GetSprite().getGlobalBounds().width/2 && _velocity.x < 0) {
        _velocity.x = 0; // Stop at bound
    }
    if(pos.x > (Game::SCREEN_WIDTH - GetSprite().getGlobalBounds().width/2) && _velocity.x > 0) {
		_velocity.x = 0; // Stop at bound
	}
	if(pos.y  < GetSprite().getGlobalBounds().height/2 && _velocity.y < 0) {
        _velocity.y = 0; // Stop at bound
	}
    if(pos.y > (Game::SCREEN_HEIGHT - GetSprite().getGlobalBounds().height/2) && _velocity.y > 0) {
		_velocity.y = 0; // Stop at bound
	}
    
//    std::cout<<"velocity is ("<<_velocity.x<<","<<_velocity.y<<")"<<std::endl;
    
	GetSprite().move(_velocity * elapsedTime);
}