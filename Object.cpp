#include "Object.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

namespace Feanwork
{
	Object::Object(int _resourceID, float _xPos, float _yPos, bool _canCollide)
	{
		setPosition(_xPos, _yPos);
		mCanCollide = _canCollide;
		mDestroy    = false;

		sf::Texture* tex = ResourceManager::getSingleton()->getResource(_resourceID);
		mSprite.setTexture(*tex);

		mAABB.left	 = (int)mX;
		mAABB.top	 = (int)mY;
		mAABB.width  = (int)tex->getSize().x / 2;
		mAABB.height = (int)tex->getSize().y / 2;
	}

	bool Object::render(Game* _game)
	{
		_game->getWindow()->draw(mSprite);
		return true;
	}

	void Object::collisionCallback(sf::Vector2f _depth, sf::Vector2f _normal)
	{
	}

	void Object::setPosition(float _x, float _y)
	{
		mX = _x;
		mY = _y;
		mAABB.left = (int)_x;
		mAABB.top  = (int)_y;
		mSprite.setPosition(_x, _y);
	}

	void Object::addPosition(float _x, float _y)
	{
		mX += _x;
		mY += _y;
		mAABB.left = (int)mX;
		mAABB.top  = (int)mY; 
		mSprite.setPosition(mX, mY);
	}
}