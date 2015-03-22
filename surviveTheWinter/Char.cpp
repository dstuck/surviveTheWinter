//
//  Char.cpp
//  surviveTheWinter
//
//  Created by David Stuck on 1/13/15.
//  Copyright (c) 2015 David Stuck. All rights reserved.
//

#include "Char.h"
#include "stdafx.h"
#include "Game.h"

Char::Char(float h, float mh):
_health(h),
_maxHealth(mh),
VisibleGameObject(true)
{
    
}

Char::~Char()
{
}

void Char::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
    //Draw health bar
    if(_health<_maxHealth) {
        sf::Vector2f rectVec(_maxHealth,10);
        sf::RectangleShape healthBar(rectVec);
        healthBar.setFillColor(sf::Color::Red);
        healthBar.setOutlineColor(sf::Color::White);
        healthBar.setOrigin(_maxHealth/2,5);
        healthBar.setPosition(GetPosition().x,GetPosition().y + GetSprite().getGlobalBounds().height/2.0 + 10);
        rw.draw(healthBar);
    }
    sf::Vector2f rectVec(_health,10);
    sf::RectangleShape healthBar(rectVec);
    healthBar.setFillColor(sf::Color::Green);
    healthBar.setOutlineColor(sf::Color::White);
    healthBar.setOrigin(_maxHealth/2,5);
    healthBar.setPosition(GetPosition().x,GetPosition().y + GetSprite().getGlobalBounds().height/2.0 + 10);
    rw.draw(healthBar);
}

void Char::ModHealth(float change) {
    _health += change;
    if(_health>_maxHealth){
        _health=_maxHealth;
    }
    else if(_health<0){
//        std::cout << "AI Died!" << std::endl;
        _health = 0;
    }
}

float Char::GetHealth() {
    return _health;
}

float Char::GetMaxHealth() {
    return _maxHealth;
}

void Char::CharMove(sf::Vector2f vec) {
//    Make sure not blocked by anything
    sf::Vector2f pos = this->GetPosition();
    if(pos.x + vec.x < GetSprite().getGlobalBounds().width/2 && vec.x < 0) {
        vec.x = 0; // Stop at bound
    }
    if(pos.x + vec.x > (Game::SCREEN_WIDTH - GetSprite().getGlobalBounds().width/2) && vec.x > 0) {
		vec.x = 0; // Stop at bound
	}
    
	if(pos.y + vec.y < GetSprite().getGlobalBounds().height/2 && vec.y < 0) {
        vec.y = 0; // Stop at bound
	}
    if(pos.y + vec.y> (Game::SCREEN_HEIGHT - GetSprite().getGlobalBounds().height/2) && vec.y > 0) {
		vec.y = 0; // Stop at bound
	}
    
    sf::Vector2f storedVec = vec;
    GetSprite().move(vec);
    bool stopped = false;
    
    std::map<std::string, VisibleGameObject*> map = Game::GetGameObjectManager().GetMap();
    for(std::map<std::string, VisibleGameObject*>::const_iterator iter = map.begin(); iter!=map.end(); iter++) {
        if(iter->second->IsSolid()) {
            stopped = true;
//            std::cout << "Position of " << iter->first <<  " is (" << iter->second->GetPosition().x << "," << iter->second->GetPosition().y << ")" << std::endl;
//            std::cout << "Touching is " << IsTouching(*(iter->second)) << std::endl;
            if((this!=iter->second)&&IsTouching(*(iter->second),0.)) {
//                std::cout << "Touching " << iter->first << std::endl;
                if(IsAbove(*(iter->second),0.) && vec.y > 0.0) {
                    vec.y = 0.0;
                }
                if(IsBelow(*(iter->second),0.) && vec.y < 0.0) {
                    vec.y = 0.0;
                }
                if(IsLeftOf(*(iter->second),0.) && vec.x > 0.0) {
                    vec.x = 0.0;
                }
                if(IsRightOf(*(iter->second),0.) && vec.x < 0.0) {
                    vec.x = 0.0;
                }
            }
        }
    }
    if(stopped) {
        GetSprite().move(-storedVec);
        GetSprite().move(vec);
    }
}


