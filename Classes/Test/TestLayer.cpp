#include "TestLayer.h"
#include "GamePlay/Character/Player/Player.h"
#include "GamePlay/Character/Test/TestObject.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"

using namespace cocos2d;

TestLayer::TestLayer()
{

}

TestLayer::~TestLayer()
{
}



bool TestLayer::init()
{
	// 親の初期化処理を呼ぶ
	if (!Layer::init())
	{
		return false;
	}

	auto debugLabel = Label::createWithTTF("Katsumi", "Font/MarkerFelt.ttf", 64);
	debugLabel->setColor(Color3B::RED);
	debugLabel->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	debugLabel->setPosition(Vec2(40, 1200));
	this->addChild(debugLabel);

	this->schedule(schedule_selector(TestLayer::update));
	auto onTouchBegan = CC_CALLBACK_2(TestLayer::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(TestLayer::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, onTouchEnd, nullptr);

	this->scheduleUpdate();

	mKatsumi = Player::create();
	mKatsumi->setPosition(200,200);
	this->addChild(mKatsumi);

	//以下、テストオブジェクト生成
	mObject = TestObject::create();
	this->addChild(mObject);

	return true;
}

void TestLayer::update(float deltaTime)
{
	mKatsumi->update(deltaTime);
}

TestLayer* TestLayer::create()
{
	auto instance = new TestLayer();

	if (instance && instance->init())
	{
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}

bool TestLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	Vec2 touchPoint = touch->getLocation();
	mObject->setPosition(touchPoint);
	return true;
}


void TestLayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	
}