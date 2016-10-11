//#include "stdafx.h"
#include "Char.h"
#include "VisibleGameObject.h"
#include <cmath>

VisibleGameObject::VisibleGameObject(float x, float y, bool solid) :
_isLoaded(false),_isSolid(solid)
{
    SetPosition(x, y);
}

VisibleGameObject::~VisibleGameObject()
{
	
}

void VisibleGameObject::Load(std::string filename)
{
	if(_image.loadFromFile(filename) == false)
	{
		_filename =  "";
		_isLoaded = false;
	}
	else
	{
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void VisibleGameObject::Draw(sf::RenderWindow & renderWindow)
{
	if(_isLoaded)
	{
		renderWindow.draw(_sprite);
	}
}


void VisibleGameObject::Update(float elapsedTime)
{
}

void VisibleGameObject::SetPosition(float x, float y)
{
    _sprite.setPosition(x,y);
//	if(_isLoaded)
//	{
//		_sprite.setPosition(x,y);
//	}
}

sf::Vector2f VisibleGameObject::GetPosition() const
{
	if(_isLoaded)
	{
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}


sf::Sprite& VisibleGameObject::GetSprite()
{
	return _sprite;
}

bool VisibleGameObject::IsLoaded() const
{
	return _isLoaded;
}

bool VisibleGameObject::IsTouching(VisibleGameObject obj, float thresh) {
//    See if x distance is less than sum of half width and same for y
    return (fabs(GetPosition().x-obj.GetPosition().x) < GetSprite().getGlobalBounds().width/2+obj.GetSprite().getGlobalBounds().width/2 + thresh) && (fabs(GetPosition().y-obj.GetPosition().y) < GetSprite().getGlobalBounds().height/2+obj.GetSprite().getGlobalBounds().height/2 + thresh);
}

bool VisibleGameObject::IsBelow(VisibleGameObject obj, float thresh) {
    return ((fabs(GetPosition().x-obj.GetPosition().x) < GetSprite().getGlobalBounds().width/2+obj.GetSprite().getGlobalBounds().width/2 + thresh) && GetPosition().y > obj.GetPosition().y);
}

bool VisibleGameObject::IsAbove(VisibleGameObject obj, float thresh) {
    return ((fabs(GetPosition().x-obj.GetPosition().x) < GetSprite().getGlobalBounds().width/2+obj.GetSprite().getGlobalBounds().width/2 + thresh) && GetPosition().y < obj.GetPosition().y);
}

bool VisibleGameObject::IsLeftOf(VisibleGameObject obj, float thresh) {
    return ((fabs(GetPosition().y-obj.GetPosition().y) < GetSprite().getGlobalBounds().height/2+obj.GetSprite().getGlobalBounds().height/2 + thresh) && GetPosition().x < obj.GetPosition().x);
}

bool VisibleGameObject::IsRightOf(VisibleGameObject obj, float thresh) {
    return ((fabs(GetPosition().y-obj.GetPosition().y) < GetSprite().getGlobalBounds().height/2+obj.GetSprite().getGlobalBounds().height/2 + thresh) && GetPosition().x > obj.GetPosition().x);
}

bool VisibleGameObject::IsSolid() {
    return _isSolid;
}

bool VisibleGameObject::GetAttacked(Char *attacker) {
    return false;
}