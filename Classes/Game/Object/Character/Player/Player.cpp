#include "Player.h"
#include "Utility/CocosAssistant/SpriteCreator.h"
#include "Utility/Collision/PhysicsCollisionManager.h"
#include "Game/Object/StageObject/Block/Block.h"
#include "Game/Object/StageObject/ObjectType.h"

using namespace cocos2d;

Player::Player() :mAngle(0), mTestIsJump(false)
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
	mSprite = SpriteCreator::create("Texture/GamePlay/Character/Player.png");
	//ついか
	this->addChild(mSprite);

	mPhysicsBody = PhysicsBody::createBox(mSprite->getContentSize());
	mPhysicsBody->setMass(1.0f);
	mPhysicsBody->setDynamic(true);
	mPhysicsBody->setCategoryBitmask( static_cast< int >(ObjectType::OBJECT_PLAYER_RED));
	mPhysicsBody->setContactTestBitmask(static_cast< int >(ObjectType::OBJECT_BLOCK_RED) | static_cast< int >(ObjectType::OBJECT_BLOCK_BLUE));
	mPhysicsBody->setCollisionBitmask(0xFFFFFFFF);
	setName("Player");

	enableCollision("Player");

	mSprite->setPhysicsBody(mPhysicsBody);

	mSprite->setName("Player");
	

	return true;
}

void Player::update(float deltaTime)
{
	/*mAngle += 0.2f;
	mSprite->setRotation(mAngle);*/
	if (!mTestIsJump) return;
	//mSprite->setPositionX(mSprite->getPositionX() + 0.5f);

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
	auto action = MoveTo::create(0.7f, targetPosition);
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

void Player::onContactBegin(cocos2d::Node* contactNode){
	stopAllActions();
}