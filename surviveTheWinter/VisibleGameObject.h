#pragma once

#include "stdafx.h"

class Char;

class VisibleGameObject
{
public:
    VisibleGameObject(float x=0, float y=0, bool solid=false);
    virtual ~VisibleGameObject();
    
    virtual void Load(std::string filename);
    virtual void Draw(sf::RenderWindow & window);
    virtual void Update(float elapsedTime);

    virtual void SetPosition(float x, float y);
    virtual sf::Vector2f GetPosition() const;
    virtual bool IsLoaded() const;
    virtual bool IsTouching(VisibleGameObject,float thresh = 0);
    virtual bool IsBelow(VisibleGameObject,float thresh = 0);
    virtual bool IsAbove(VisibleGameObject,float thresh = 0);
    virtual bool IsRightOf(VisibleGameObject,float thresh = 0);
    virtual bool IsLeftOf(VisibleGameObject,float thresh = 0);
    virtual bool IsSolid();
    virtual bool GetAttacked(Char *);

protected:
    sf::Sprite& GetSprite();
    bool _isSolid;
    
private:
	sf::Sprite  _sprite;
	sf::Texture _image;
	std::string _filename;
	bool _isLoaded;
};
