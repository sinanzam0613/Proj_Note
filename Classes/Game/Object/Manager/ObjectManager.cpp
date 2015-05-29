#include "ObjectManager.h"
#include "Game/Object/Character/Player/Player.h"
#include "Game/Object/Test/TestObject.h"
#include "Utility/Collision/DistanceCheck.h"
#include "../Manager/PlayerManager.h"

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

	/*mKatsumi = Player::create("Player");
	mKatsumi->setPosition(Vec2(200, 200));
	this->addChild(mKatsumi);*/

	mPlayerManager = PlayerManager::create();
	mPlayerManager->add(Vec2(100,200),Vec2(400,200));
	this->addChild(mPlayerManager);

	//以下、テストオブジェクト生成
	mObject = TestObject::create();
	mObject->setPosition(300,500);
	this->addChild(mObject);

	return true;
}

void ObjectManager::update(float deltaTime)
{
	//mKatsumi->update(deltaTime);

	/*if (distanceCheck())
	{
		//mKatsumi->jump(mObject->getPosition());
	}*/
	mPlayerManager->update(deltaTime);
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