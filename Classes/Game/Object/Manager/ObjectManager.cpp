#include "ObjectManager.h"
#include "Game/Object/Character/Player/Player.h"
#include "Game/Object/Test/TestObject.h"
#include "Utility/Collision/DistanceCheck.h"
#include "../Manager/PlayerManager.h"
#include "Game/Object/Character/Enemy/RestEnemy.h"
#include "../Manager/EnemyManager.h"
#include "Game/Object/Character/Player/DeadAnimation.h"


using namespace cocos2d;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	mEnemyManager->release();
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
	mPlayerManager->add(Vec2(100,200),Vec2(400,200),5,5);
	this->addChild(mPlayerManager);

	//以下、テストオブジェクト生成
	mObject = TestObject::create();
	mObject->setPosition(Vec2(300,0));
	this->addChild(mObject);

	//以下、エネミーのテスト
	mEnemy = RestEnemy::create(Vec2());
	this->addChild(mEnemy);

	//以下、エネミーマネージャーのテスト
	mEnemyManager = EnemyManager::create();
	mEnemyManager->retain();
	mEnemyManager->add(Vec2(500,-52));
	mEnemyManager->add(Vec2(300, -52));
	this->addChild(mEnemyManager);
	return true;
}

void ObjectManager::update(float deltaTime)
{
	//mKatsumi->update(deltaTime);

	/*if (distanceCheck())
	{
		mEnemy->jump();
	}*/
	mPlayerManager->update(deltaTime);
	mEnemy->update(deltaTime);
	mEnemyManager->update(deltaTime);
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
	//mObject->setPosition(touchPoint);
	mObject->dead();
}

bool ObjectManager::distanceCheck()
{
	float distance = DistanceCheck::checkX(mObject, mEnemy);
	const float maximumDistance = 200;	//ジャンプできる最大距離
	if (distance > maximumDistance)
	{
		return false;
	}
	return true;
}