#include "RestEnemy.h"
#include "Utility/Action/Jump.h"
#include "Utility/CocosAssistant/SpriteCreator.h"

using namespace cocos2d;

RestEnemy::RestEnemy()
{
}

RestEnemy::~RestEnemy()
{
}

bool RestEnemy::init(const cocos2d::Vec2& position)
{
	if (!Node::init())return false;
	mSprite = SpriteCreator::createPhysicsBox("Texture/GamePlay/Character/RestEnemy.png", cocos2d::Size(112,52));
	mSprite->setPosition(Vec2(position.x,-52));
	addChild(mSprite);
	mTimer.reset();

	mTimer.begin();
	return true;
}

void RestEnemy::update(float deltaTime)
{
	mTimer.update();
	const int jumpTime = (5 + 4)*60;
	if (mTimer.getTime() >= jumpTime)
	{
		jump();
		mTimer.reset();
		mTimer.begin();
	}
}

void RestEnemy::jump()
{
	if (mSprite->getActionByTag(1)){

		return;
	}
	auto action = JumpBy::create(2, Vec2(0, 0), 400, 1);
	action->setTag(1);
	mSprite->runAction(action);
	//mTimer.begin();
}

RestEnemy* RestEnemy::create(const cocos2d::Vec2& position)
{
	auto instance = new RestEnemy();

	if (instance && instance->init(position))
	{
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}

const Vec2& RestEnemy::getPosition()const
{
	return mSprite->getPosition();
}