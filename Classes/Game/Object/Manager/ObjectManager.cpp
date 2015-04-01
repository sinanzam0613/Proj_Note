#include "ObjectManager.h"
#include "Game/Object/Character/Player/Player.h"
#include "Game/Object/Test/TestObject.h"
#include "Utility/Collision/DistanceCheck.h"

using namespace cocos2d;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

bool ObjectManager::init()
{
	if (!Node::init())
	{
		return false;
	}

	mKatsumi = Player::create();
	mKatsumi->setPosition(Vec2(200, 200));
	this->addChild(mKatsumi);

	//以下、テストオブジェクト生成
	mObject = TestObject::create();
	mObject->setPosition(300,500);
	this->addChild(mObject);

	return true;
}

void ObjectManager::update(float deltaTime)
{
	mKatsumi->update(deltaTime);

	if (distanceCheck())
	{
		mKatsumi->jump(mObject->getPosition());
	}
}

ObjectManager* ObjectManager::create()
{
	auto instance = new ObjectManager();

	if (instance && instance->init())
	{
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}

void ObjectManager::onTouchBegan(Vec2 touchPoint)
{
	mObject->setPosition(touchPoint);
}

bool ObjectManager::distanceCheck()
{
	float distance = DistanceCheck::Check(mKatsumi, mObject);
	const float maximumDistance = 200;	//ジャンプできる最大距離
	const float minDistance = 50;		//近すぎるとジャンプしない
	if (distance > maximumDistance||
		distance < minDistance)
	{
		return false;
	}
	return true;
}