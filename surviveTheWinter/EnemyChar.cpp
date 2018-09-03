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


EnemyChar::EnemyChar(float x, float y) : Char(50.0, 50.0, x, y, 5, 0),
                                         _total_time(0.0), _velocity(0.0,0.0),
                                         _max_speed(400.0f), _cur_speed(400.0f),
                                         _attack_cool_time(0.0f), _attack_delay(1.0f)
{
    sf::Vector2f zeroV(0,0);
    _curMove = new MoveWalk(zeroV,1);
    _decision_time = _curMove->GetTime();
	Load(resourcePath() + "enemy.jpg");
	assert(IsLoaded());
    srand(static_cast<unsigned>(time(NULL)));
    
	GetSprite().setOrigin(GetSprite().getGlobalBounds().width/2, GetSprite().getGlobalBounds().height/2);
}

EnemyChar::~EnemyChar()
{
}

sf::Vector2f EnemyChar::GetVelocity() const
{
	return _velocity;
}

AIMove * EnemyChar::GetNextMove() {
    if(_curMove!=NULL){
        delete _curMove;
    }
    
    float timeRange = 0.3;
    float timeMid = 0.8;
    int speedRange = 100;
    sf::Vector2f bias(0,0);
    
    PlayerChar* thePlayer = dynamic_cast<PlayerChar*>(Game::GetGameObjectManager().Get("Player1"));
    if(thePlayer!=NULL) {
        sf::Vector2f pVec = thePlayer->GetPosition();
        
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
    _total_time += elapsedTime;
    _decision_time -= elapsedTime;
    if(_attack_cool_time > 0.0) {
        _attack_cool_time -= elapsedTime;
    }
    if(_decision_time <= 0.0) {
        _curMove = GetNextMove();
        _decision_time = _curMove->GetTime();
    }
    _velocity = _curMove->GetVelocity();
    
	CharMove(_velocity * elapsedTime);
    
//    Damage everyone!
    if(_attack_cool_time <= 0.0) {
        for(auto vis_obj: Game::GetGameObjectManager().GetMap()) {
            if(IsTouching(*vis_obj.second, 20) and vis_obj.second!=this) {
                vis_obj.second->GetAttacked(this);
                _attack_cool_time = _attack_delay;
            }
        }

    }
}
