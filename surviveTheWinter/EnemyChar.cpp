//
//  EnemyChar.cpp
//  surviveTheWinter
//
//  Created by David Stuck on 1/12/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#include "stdafx.h"
#include "EnemyChar.h"
#include "AIChar.h"
#include "Game.h"
#include "MoveWalk.h"
#include "VectorUtil.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>


EnemyChar::EnemyChar(float x, float y) : _totalTime(0.0), _velocity(0.0,0.0),
                                         _maxSpeed(400.0f), _curSpeed(400.0f),
                                         Char(50.0, 50.0, x, y)
{
    sf::Vector2f zeroV(0,0);
    _curMove = new MoveWalk(zeroV,1);
    _decisionTime = _curMove->GetTime();
	Load(resourcePath() + "enemy.jpg");
	assert(IsLoaded());
    srand (time(NULL));
    
	GetSprite().setOrigin(GetSprite().getGlobalBounds().width/2, GetSprite().getGlobalBounds().height/2);
    
}

EnemyChar::~EnemyChar()
{
}

//void EnemyChar::Draw(sf::RenderWindow & rw)
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

sf::Vector2f EnemyChar::GetVelocity() const
{
	return _velocity;
}

AIMove * EnemyChar::GetNextMove() {
    if(_curMove!=NULL){
        delete _curMove;
    }
    
    double timeRange = 0.3;
    double timeMid = 0.8;
    double tooClose = 300.0;
    int speedRange = 100;
    sf::Vector2f bias(0,0);
    
    PlayerChar* thePlayer = dynamic_cast<PlayerChar*>(Game::GetGameObjectManager().Get("Player1"));
    if(thePlayer!=NULL) {
        sf::Vector2f pVec = thePlayer->GetPosition();
        float pDist = VectorUtil::VDist(pVec, GetPosition());
        
        bias = GetPosition()-pVec;
        VectorUtil::VNormalize(bias);
        VectorUtil::VScale(bias,float(speedRange)/10);
    }
    
    sf::Vector2f moveVec(rand()%(2*speedRange)-speedRange+bias.x,rand()%(2*speedRange)-speedRange+bias.y);
    MoveWalk * nMove = new MoveWalk(moveVec,float(rand())/RAND_MAX*timeRange/2+timeMid);
    return nMove;
}

void EnemyChar::Update(float elapsedTime)
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
    
//    sf::Vector2f pos = this->GetPosition();
//    
//	if(pos.x  < GetSprite().getGlobalBounds().width/2 && _velocity.x < 0) {
//        _velocity.x = 0; // Stop at bound
//    }
//    if(pos.x > (Game::SCREEN_WIDTH - GetSprite().getGlobalBounds().width/2) && _velocity.x > 0) {
//		_velocity.x = 0; // Stop at bound
//	}
//	if(pos.y  < GetSprite().getGlobalBounds().height/2 && _velocity.y < 0) {
//        _velocity.y = 0; // Stop at bound
//	}
//    if(pos.y > (Game::SCREEN_HEIGHT - GetSprite().getGlobalBounds().height/2) && _velocity.y > 0) {
//		_velocity.y = 0; // Stop at bound
//	}
//    
    //    std::cout<<"velocity is ("<<_velocity.x<<","<<_velocity.y<<")"<<std::endl;
    
	CharMove(_velocity * elapsedTime);
    
//    Damage everyone!
    AIChar* theAI = dynamic_cast<AIChar*>(Game::GetGameObjectManager().Get("AI1"));
//    std::cout << VectorUtil::VDist(GetPosition(),theAI->GetPosition()) << std::endl;
    if(theAI!=NULL) {
        if(IsTouching(*theAI,20)) {
//            std::cout << "Touching!!" << std::endl;
            theAI->ModHealth(-5*elapsedTime,GetPosition());
       
        }
    }
    PlayerChar* thePlayer = dynamic_cast<PlayerChar*>(Game::GetGameObjectManager().Get("Player1"));
    if(thePlayer!=NULL) {
        if(IsTouching(*thePlayer,20)) {
            thePlayer->ModHealth(-10*elapsedTime);
        }
    }
}
