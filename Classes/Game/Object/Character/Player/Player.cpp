#include "Player.h"
#include "Utility/CocosAssistant/SpriteCreator.h"
#include "Utility/Collision/PhysicsCollisionManager.h"

using namespace cocos2d;

Player::Player() :mAngle(0), mTestIsJump(false), mTestCount(0)
{
}

Player::~Player()
{

}

bool Player::init(const std::string& fileName)
{
	if (!Node::init())
	{
		return false;
	}

	const std::string file = "Texture/GamePlay/Character/" + fileName;
	mSprite = SpriteCreator::create(file);

	mPhysicsBody = PhysicsBody::createBox(mSprite->getContentSize());
	mPhysicsBody->setMass(1.0f);
	mPhysicsBody->setDynamic(true);
	mPhysicsBody->setEnable(true);
	mPhysicsBody->setContactTestBitmask(true);
	mPhysicsBody->setCollisionBitmask(true);

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
	if (mSprite->getPositionY() < 0){
		mSprite->stopAllActions();
		mSprite->setPosition(Vec2(100, 250));
		mTestIsJump = true;
	}
	jump(Vec2());

	CCLOG("X : %f", mSprite->getAnchorPoint().x);
	CCLOG("Y : %f", mSprite->getAnchorPoint().y);

	

}

Player* Player::create(const std::string& fileName)
{
	auto instance = new Player();

	if (instance && instance->init(fileName))
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
	if (mSprite->getActionByTag(1)||mSprite->getActionByTag(2))
	{
		return;
	}

	//auto action = JumpTo::create(2.f, Vec2(targetPosition.x,targetPosition.y + mSprite->getContentSize().height / 4),
	//targetPosition.y / 2, 1);
	//すでにジャンプが実行されているのであれば何もしない。

	auto action = JumpBy::create(2.f, Vec2(100, 0),300, 1);

	action->setTag(1);

	auto seq = Sequence::create(action, CallFunc::create([this](){ mPhysicsBody->setDynamic(true); }), nullptr);

	seq->setTag(2);
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