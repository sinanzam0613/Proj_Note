#include "Player.h"
#include "Utility/CocosAssistant/SpriteCreator.h"

using namespace cocos2d;

Player::Player() :mAngle(0)
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
	mSprite = SpriteCreator::create("GamePlay/Character/Player.png");
	
	this->addChild(mSprite);


	return true;
}

void Player::update(float deltaTime)
{
	mAngle += 0.2f;
	mSprite->setRotation(mAngle);

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

void Player::jump(Vec2 targetPosition)
{
	//すでにジャンプが実行されているのであれば何もしない。
	if (mSprite->getActionByTag(1))
	{
		return;
	}
	auto action = JumpTo::create(0.7f, targetPosition, 50, 1);
	action->setTag(1);
	mSprite->runAction(action);
}

void Player::setPosition(const Vec2& position)
{
	mSprite->setPosition(position);
}

const Vec2& Player::getPosition()const
{
	return mSprite->getPosition();
}
