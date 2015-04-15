#include "HigeLayer.h"
#include "Game/Object/Manager/NoteManager.h"
#include "Utility/Audio/ADX2Player.h"
#include "Utility/Audio/Define/Sample_DoReMi.h"
#include "Game/Object/StageObject/Rest/Rest.h"
#include "Game/Object/StageObject/Goal/Goal.h"
#include "Game/Object/Character/Player/Player.h"
#include "Utility/Collision/PhysicsListener.h"
#include <math.h>
#include <random>

using namespace cocos2d;

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()

HigeLayer::HigeLayer(){
	//目る専ぬツイスター
	srand((unsigned)time(NULL));
}

HigeLayer::~HigeLayer() {
	mNoteManager->release();
}

bool HigeLayer::init() {
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255), 1280, 720)) return false;

	this->schedule(schedule_selector(HigeLayer::update));

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HigeLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HigeLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HigeLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	auto back = Sprite::create("Texture/GamePlay/Character/NoteLine.png");
	back->setAnchorPoint(Vec2(0,0));
	back->setPosition(Vec2(0, 5));
	addChild(back);

	mNoteManager = NoteManager::create(this);
	mNoteManager->retain();

	auto rest = Rest::create("Texture/GamePlay/Character/2Rest.png");
	rest->setPosition(Vec2(100, 50));
	addChild(rest);

	auto goal = Goal::create("Texture/GamePlay/Character/End.png");
	goal->setPosition(Vec2(1250, 500));
	addChild(goal);

	auto sprite = Player::create();
	sprite->setPosition(Vec2(100, 230));
	sprite->setScale(0.9f);
	sprite->setTag(555);
	addChild(sprite);

	auto lis = PhysicsListener::create();
	addChild(lis);

	return true;
}

void HigeLayer::update(float deltaTime) {
	auto sprite = (Player*)getChildByTag(555);

	sprite->update(deltaTime);
}


bool HigeLayer::onTouchBegan(Touch* touch, Event* event) {
	Point pos = this->convertTouchToNodeSpace(touch);

	mNoteManager->onTouchBegan(pos);

	auto sprite = (Player*)getChildByTag(555);

	sprite->setPosition(Vec2(100, 250));
	sprite->jump(Vec2(sprite->getPositionX()+1000, sprite->getPositionY() + 700));
	sprite->mTestIsJump = true;

	return true;
}

void HigeLayer::onTouchMoved(Touch* touch, Event* event) {
	Point pos = this->convertTouchToNodeSpace(touch);
	mNoteManager->onTouchMove(pos);
}

void HigeLayer::onTouchEnded(Touch* touch, Event* event) {
	Point pos = this->convertTouchToNodeSpace(touch);
	mNoteManager->onTouchEnd(pos);

	mNoteManager->onTouchBegan(pos);

	auto sprite = (Player*)getChildByTag(555);

	sprite->mTestIsJump = false;
}

HigeLayer* HigeLayer::create() {
	auto instance = new HigeLayer();

	if (instance && instance->init()) {
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}