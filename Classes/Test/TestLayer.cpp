#include "TestLayer.h"
#include "GamePlay/Character/Player/Player.h"

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

	mKatsumi = Player::createCharacter();
	mKatsumi->setPosition(200,200);
	this->addChild(mKatsumi);
	return true;
}

void TestLayer::update(float deltaTime)
{

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