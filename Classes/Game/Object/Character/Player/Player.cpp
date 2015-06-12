#include "Player.h"
#include "Utility/CocosAssistant/SpriteCreator.h"
#include "Utility/Collision/PhysicsCollisionManager.h"
#include "Game/Object/StageObject/Block/Block.h"
#include "Game/Object/StageObject/ObjectType.h"
#include "Utility/Action/Jump.h"

using namespace cocos2d;

Player::Player(ObjectType type, float jumpTime) :mAngle(0), mTestIsJump(false), mTestCount(0), mJumpTime(jumpTime), mIsDead(false),mJumpCount(0)
{
}

Player::~Player()
{
}

bool Player::init(const std::string& fileName, ObjectType type)
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

	mPhysicsBody->setCategoryBitmask(static_cast<int>(type));
	if (type == ObjectType::OBJECT_PLAYER_RED){
		mPhysicsBody->setContactTestBitmask(0xFFFFFFFF);
		mPhysicsBody->setCollisionBitmask(static_cast<int>(ObjectType::OBJECT_BLOCK_RED));
	}
	else if (type == ObjectType::OBJECT_PLAYER_BLUE)
	{
		mPhysicsBody->setContactTestBitmask(0xFFFFFFFF);
		mPhysicsBody->setCollisionBitmask(static_cast<int>(ObjectType::OBJECT_BLOCK_BLUE));
	}

	if (type == ObjectType::OBJECT_PLAYER_RED)
	{
		setName("Player");
		enableCollision("Player");
		mSprite->setName("Player");
	}
	else
	{
		setName("Player2");
		enableCollision("Player2");
		mSprite->setName("Player2");
	}
	
	mSprite->setPosition(Vec2(0, 0));

	mSprite->setPhysicsBody(mPhysicsBody);
	this->addChild(mSprite);

	mSprite->setScale(0.5f);
	mJumpTime = 2.0f;
	mIsJump = false;
	mDuration = 0;

	return true;
}

void Player::update(float deltaTime)
{
	if (mSprite->getPositionY() < -mSprite->getContentSize().height){
		mSprite->stopAllActions();
		mSprite->setPosition(Vec2(100, 250));
		mIsJump = false;
		mTestIsJump = true;
		mIsDead = true;
	}
	//jump(Vec2());

	//CCLOG("X : %f", mSprite->getAnchorPoint().x);
	//CCLOG("Y : %f", mSprite->getAnchorPoint().y);

	mDuration += deltaTime;

	



}

Player* Player::create(const std::string& fileName,ObjectType type,float jumpTime)
{
	auto instance = new Player(type,jumpTime);

	if (instance && instance->init(fileName,type))
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
	mDuration = 0;

	mTargetPos = targetPosition;

	auto action = myAction::Jump::create(mJumpTime, Vec2(targetPosition.x,targetPosition.y + mSprite->getContentSize().height / 4),
	targetPosition.y / 2, 1);

	auto seq = Sequence::create(action, CallFunc::create([this](){ mPhysicsBody->setDynamic(true); }), nullptr);

	seq->setTag(1);

	mSprite->runAction(seq);

	mPhysicsBody->setDynamic(false);

	mIsJump = true;
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
	
	if ( std::strstr(static_cast<Block*>(contactNode)->getName().c_str(),"Block")){
		if (!static_cast<Block*>(contactNode)->isChange()) return;
		mSprite->stopAllActions();																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																								// 記念AGO
		mJumpCount++;

		mIsJump = false;
	}
}

void Player::changeJumpTime(float changetime){

	if (!mSprite->getActionByTag(1) || mJumpTime == changetime || mDuration > mJumpTime) return;

	mJumpTime = changetime;

	float rest = 0 < changetime - mDuration ? changetime - mDuration : 0.1f;

	mSprite->stopAllActions();

	auto action = myAction::Jump::create(rest, Vec2(mTargetPos.x, mTargetPos.y + mSprite->getContentSize().height / 4), mTargetPos.y / 2, 1);

	auto seq = Sequence::create(action, CallFunc::create([this](){ mPhysicsBody->setDynamic(true); }), nullptr);

	seq->setTag(1);

	mSprite->runAction(seq);
}


bool Player::isJump(){
	return mIsJump;
	//return mSprite->getActionByTag(1) != nullptr ? true : false;
}

unsigned int Player::jumpCount(){
	return mJumpCount;	
}

bool Player::isDead()const
{
	return mIsDead;

}