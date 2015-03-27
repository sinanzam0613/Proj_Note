#include "ObjectManager.h"
#include "GamePlay/Character/Player/Player.h"
#include "GamePlay/Character/Test/TestObject.h"

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
	mKatsumi->setPosition(200, 200);
	this->addChild(mKatsumi);

	//以下、テストオブジェクト生成
	mObject = TestObject::create();
	this->addChild(mObject);
}

void ObjectManager::update(float deltaTime)
{
	mKatsumi->update(deltaTime);
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