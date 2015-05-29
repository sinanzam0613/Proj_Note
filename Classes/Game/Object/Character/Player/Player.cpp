#include "Player.h"
#include "Utility/CocosAssistant/SpriteCreator.h"
#include "Utility/Collision/PhysicsCollisionManager.h"
#include "Game/Object/StageObject/Block/Block.h"
#include "Game/Object/StageObject/ObjectType.h"
#include "Utility/Action/Jump.h"

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

	mPhysicsBody->setCategoryBitmask(static_cast<int>(ObjectType::OBJECT_PLAYER_RED));
	mPhysicsBody->setContactTestBitmask(static_cast<int>(ObjectType::OBJECT_BLOCK_RED) |
		static_cast<int>(ObjectType::OBJECT_BLOCK_BLUE));
	mPhysicsBody->setCollisionBitmask(static_cast<int>(ObjectType::OBJECT_BLOCK_RED) |
		static_cast<int>(ObjectType::OBJECT_BLOCK_BLUE));

	setName("Player");
	enableCollision("Player");
	mSprite->setName("Player");
	
	mSprite->setPosition(Vec2(0, 0));


	mSprite->setPhysicsBody(mPhysicsBody);
	this->addChild(mSprite);
		
	mTestIsJump = true;

	mSprite->setScale(0.5f);
	mJumpTime = 2.0f;
	
	mTestJumpTimer = 0;

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

	//CCLOG("X : %f", mSprite->getAnchorPoint().x);
	//CCLOG("Y : %f", mSprite->getAnchorPoint().y);

	mTestJumpTimer += deltaTime;

	

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
	if (mSprite->getActionByTag(1))
	{
		return;
	}
	mTestJumpTimer = 0;

	mTargetPos = targetPosition;


	auto action = myAction::Jump::create(mJumpTime, Vec2(targetPosition.x,targetPosition.y + mSprite->getContentSize().height / 4),
	targetPosition.y / 2, 1);

	auto seq = Sequence::create(action, CallFunc::create([this](){ mPhysicsBody->setDynamic(true); }), nullptr);

	seq->setTag(1);

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

void Player::changeSpeed(float speed){

	mSprite->stopAllActions();

	mJumpTime = speed;

	float unko = speed - mTestJumpTimer;

	if (unko <= 0) unko = 0.1f;

	auto action = myAction::Jump::create(unko, Vec2(mTargetPos.x, mTargetPos.y + mSprite->getContentSize().height / 4), 0, 1);

	auto seq = Sequence::create(action, CallFunc::create([this](){ mPhysicsBody->setDynamic(true); }), nullptr);

	seq->setTag(1);

	mSprite->runAction(seq);
}