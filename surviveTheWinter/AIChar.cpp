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


AIChar::AIChar(float x, float y) : Char(50.0, 50.0, x, y), _totalTime(0.0),
                                   _velocity(0.0,0.0), _maxSpeed(400.0f),
                                   _curSpeed(400.0f)

{
    sf::Vector2f zeroV(0,0);
    _curMove = new MoveWalk(zeroV,1);
    _decisionTime = _curMove->GetTime();
	Load(resourcePath() + "monster.jpg");
	assert(IsLoaded());
    srand(time(NULL));
    
	GetSprite().setOrigin(GetSprite().getGlobalBounds().width/2, GetSprite().getGlobalBounds().height/2);
    
}

AIChar::~AIChar()
{
}

//void AIChar::Draw(sf::RenderWindow & rw)
//{
//	VisibleGameObject::Draw(rw);
//    //Draw health bar
//    sf::Vector2f rectVec(_health,10);
//    sf::RectangleShape healthBar(rectVec);
//    healthBar.setFillColor(sf::Color::Green);
//    healthBar.setOutlineColor(sf::Color::Black);
//    healthBar.setOrigin(_maxHealth/2,5);
//    healthBar.setPosition(GetPosition().x,GetPosition().y + GetSprite().getGlobalBounds().height/2.0 + 10);
//    rw.draw(healthBar);
//}

sf::Vector2f AIChar::GetVelocity() const
{
	return _velocity;
}

AIMove * AIChar::GetNextMove() {
    if(_curMove!=NULL){
        delete _curMove;
    }
    
    float timeRange = 0.3;
    float timeMid = 0.4;
    float tooClose = 300.0;
    int speedRange = 200;
    sf::Vector2f bias(0,0);
    
    VisibleGameObject *thePlayer = Game::GetGameObjectManager().Get("Player1");
    if(thePlayer!=NULL) {
        sf::Vector2f pVec = thePlayer->GetPosition();
        float pDist = VectorUtil::VDist(pVec, GetPosition());
        
        if(pDist<tooClose) {
            bias = GetPosition()-pVec;
            VectorUtil::VNormalize(bias);
            speedRange = 300;
            VectorUtil::VScale(bias,float(speedRange)/1.5);
            timeMid = .6;
        }
        else {
            bias = pVec-GetPosition();
            VectorUtil::VNormalize(bias);
            VectorUtil::VScale(bias,float(speedRange)/4.0);
        }
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
    if(_danger_dir != sf::Vector2f(0, 0)) {
        if(_curMove!=NULL){
            delete _curMove;
        }
        int speedRange = 100;
        sf::Vector2f moveVec(
            rand()%(2*speedRange)-speedRange+100.0f * _danger_dir.x,
            rand()%(2*speedRange)-speedRange+100.0f * _danger_dir.y
        );
        MoveWalk *fleeMove = new MoveWalk(moveVec,.4);
        _curMove = fleeMove;
        _danger_dir = sf::Vector2f(0, 0);
        _decisionTime = _curMove->GetTime();
    }
    if(_decisionTime <= 0.0) {
        _curMove = GetNextMove();
        _decisionTime = _curMove->GetTime();
    }
    _velocity = _curMove->GetVelocity();
    
//    _curMove->PrintMove();
    
	CharMove(_velocity * elapsedTime);
}
