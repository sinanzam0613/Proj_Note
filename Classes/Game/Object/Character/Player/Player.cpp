#include "Player.h"
#include "Utility/CocosAssistant/SpriteCreator.h"
#include "Utility/Collision/PhysicsCollisionManager.h"
#include "Game/Object/StageObject/Block/Block.h"
#include "Game/Object/StageObject/ObjectType.h"

using namespace cocos2d;

Player::Player() :mAngle(0), mTestIsJump(false), mTestCount(0)
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

	mPhysicsBody = PhysicsBody::createBox(mSprite->getContentSize());
	mPhysicsBody->setMass(1.0f);
	mPhysicsBody->setDynamic(true);
	mPhysicsBody->setEnable(true);
	mPhysicsBody->setContactTestBitmask(true);
	mPhysicsBody->setCollisionBitmask(true);

	mPhysicsBody->setCategoryBitmask( static_cast< int >(ObjectType::OBJECT_PLAYER_RED));
	mPhysicsBody->setContactTestBitmask(static_cast< int >(ObjectType::OBJECT_BLOCK_RED) | static_cast< int >(ObjectType::OBJECT_BLOCK_BLUE));
	mPhysicsBody->setCollisionBitmask(0xFFFFFFFF);
	setName("Player");

	enableCollision("Player");

	mSprite->setName("Player");
	
	mSprite->setPosition(Vec2(0, 0));


	mSprite->setPhysicsBody(mPhysicsBody);
	this->addChild(mSprite);

	mTestIsJump = true;

	mSprite->setScale(0.5f);

	return true;
}

void Player::update(float deltaTime)
{
	/*mAngle += 0.2f;
	mSprite->setRotation(mAngle);*/

	if (mSprite->getPositionY() < 0){
		mSprite->stopAllActions();
		mSprite->setPosition(Vec2(100, 250));
		mTestIsJump = true;
	}

	CCLOG("X : %f", mSprite->getAnchorPoint().x);
	CCLOG("Y : %f", mSprite->getAnchorPoint().y);

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

	auto action = JumpTo::create(2.f, Vec2(targetPosition.x,targetPosition.y + mSprite->getContentSize().height / 4),
	targetPosition.y / 2, 1);
	action->setTag(1);

	auto seq = Sequence::create(action, CallFunc::create([this](){ mPhysicsBody->setDynamic(true); }), nullptr);

	mSprite->runAction(seq);

	mPhysicsBody->setDynamic(false);
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
	mSprite->stopAllActions();
	mTestCount++;
	mTestIsJump = true;
}