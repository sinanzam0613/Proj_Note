#include "Player.h"

using namespace cocos2d;

Player::Player()
{
}

Player::~Player()
{
}

bool Player::init()
{
	if (!Node::init())
	{
		return false;
	}

	mSprite = Sprite::create("Character/Player.png");
	this->addChild(mSprite);

	return true;
}

void Player::update(float deltaTime)
{

}

Player* Player::createCharacter()
{
	auto instance = new Player();

	if (instance && instance->init())
	{
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}