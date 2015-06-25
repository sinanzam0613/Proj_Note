#include "Player.h"
#include "Utility/CocosAssistant/SpriteCreator.h"
#include "Utility/Collision/PhysicsCollisionManager.h"
#include "Utility/Action/Jump.h"
#include "Game/Object/StageObject/ObjectType.h"
#include "Game/Object/Character/Player/DeadAnimation.h"
#include "Utility/Animation/SimpleParticle.h"
#include "Utility/Animation/SpriteAnimation.h"

using namespace cocos2d;

Player::Player(ObjectType type, float jumpTime) :  mJumpTime(jumpTime), mState(NORMAL),mJumpCount(0)
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
	mPhysicsBody = PhysicsBody::createBox(cocos2d::Size(mSprite->getContentSize().width, mSprite->getContentSize().height / 4));
	mPhysicsBody->setMass(1.0f);
	mPhysicsBody->setDynamic(true);
	mPhysicsBody->setPositionOffset(Vec2(0, -40));
	mPhysicsBody->setGravityEnable(false);

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
	mState = NORMAL;
	mDuration = 0;

	return true;
}

void Player::update(float deltaTime)
{
	if (mState == DEAD) return;

	if (mSprite->getPositionY() < -mSprite->getContentSize().height ){
		mSprite->stopAllActions();
		DeadAnimation anim;
		anim.action(mSprite);
		mPhysicsBody->setDynamic(false);
		mState = DEAD;
	}
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
	if (!mState == NORMAL){ return; }

	mDuration = 0;
	
	mPhysicsBody->setGravityEnable(true);

	mTargetPos = targetPosition;

	auto action = myAction::Jump::create(mJumpTime, Vec2(targetPosition.x,targetPosition.y + mSprite->getContentSize().height / 4),
	targetPosition.y / 2, 1);

	auto seq = Sequence::create(action, CallFunc::create([this](){ mPhysicsBody->setDynamic(true); }), nullptr);

	seq->setTag(1);

	mSprite->runAction(seq);

	mPhysicsBody->setDynamic(false);

	mState = JUMP;

	auto p = SimpleParticle::create("Particle/JumpEffect.plist", Vec2(getPosition().x, getPosition().y - 20));
	getParent()->addChild(p);
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

	if (!mState == JUMP){ return; }

	if (std::strstr(contactNode->getName().c_str(), "Rest")) {
		mSprite->stopAllActions();
		auto action = MoveTo::create(2.5f, Vec2(mSprite->getPositionX(), 0));
		this->runAction(action);
		mState = NORMAL;
		return;
	}

	if ( std::strstr(contactNode->getName().c_str(),"Block")){
		if (!std::strstr(contactNode->getName().c_str(), "After")){
			mState = MISS;
			return;
		}

		mSprite->stopAllActions();

		mJumpCount++;

		mState = NORMAL;

		if (mSprite->getName() == "Player2") {
			mSprite->setOpacity(0);
			Util::SpriteAnimation spriteAnimetion("Texture/GamePlay/Character/");
			auto anime = spriteAnimetion.create("Helper2_", 6, 0.08f, true, false);
			anime->setAnchorPoint(Vec2::ZERO);
			mSprite->addChild(anime);
		}
		else if (mSprite->getName() != "Player2"){
			mSprite->setOpacity(0);
			Util::SpriteAnimation spriteAnimetion("Texture/GamePlay/Character/");
			auto anime = spriteAnimetion.create("Helper1_", 6, 0.08f, true, false);
			anime->setAnchorPoint(Vec2::ZERO);
			mSprite->addChild(anime);
		}
	}

	if (std::strstr(contactNode->getName().c_str(), "Fermata")) {
		changeJumpTime(3);
	}
}

void Player::changeJumpTime(float changetime){

	if (!mSprite->getActionByTag(1) || mJumpTime == changetime || mDuration > mJumpTime) return;

	mJumpTime = changetime;

	float rest = 0 < changetime - mDuration ? changetime - mDuration : 0.5f;

	mSprite->stopAllActions();

	auto action = myAction::Jump::create(rest, Vec2(mTargetPos.x, mTargetPos.y + mSprite->getContentSize().height / 4), mTargetPos.y / 2, 1);

	auto seq = Sequence::create(action, CallFunc::create([this](){ mPhysicsBody->setDynamic(true); }), nullptr);

	seq->setTag(1);

	mSprite->runAction(seq);
}

PLAYERSTATE Player::getState(){
	return mState;
}

unsigned int Player::jumpCount(){
	return mJumpCount;	
}

