#include "Player.h"
#include "../SpriteCreator.h"

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

	const Size size = Size(120,180);

	mSprite = SpriteCreator::createPhysicsBox("GamePlay/Character/Player.png", size);
	this->addChild(mSprite);
	

	return true;
}

void Player::update(float deltaTime)
{

}

Player* Player::create()
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

void Player::Jump(Vec2 targetPosition)
{
	//すでにジャンプが実行されているのであれば何もしない。
	if (this->getActionByTag(1))
	{
		return;
	}
	auto action = JumpTo::create(0.7f, targetPosition, 50, 1);
	action->setTag(1);
	this->runAction(action);
}
