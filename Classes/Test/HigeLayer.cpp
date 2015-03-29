#include "HigeLayer.h"
#include "GamePlay\Object\Note.h"

using namespace cocos2d;

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()

HigeLayer::HigeLayer() {}

HigeLayer::~HigeLayer() {}

bool HigeLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	this->schedule(schedule_selector(HigeLayer::update));

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HigeLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HigeLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HigeLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

void HigeLayer::update(float deltaTime)
{
}


bool HigeLayer::onTouchBegan(Touch* touch, Event* event){
	mNote = Note::createObject();
	this->addChild(mNote);
	Point pos = this->convertTouchToNodeSpace(touch);
	this->mNote->setPosition(pos);
	return true;
}

void HigeLayer::onTouchMoved(Touch* touch, Event* event){
	Point pos = this->convertTouchToNodeSpace(touch);
	this->mNote->setPosition(pos);
}

void HigeLayer::onTouchEnded(Touch* touch, Event* event){
	Point pos = this->convertTouchToNodeSpace(touch);
	this->mNote->setPosition(pos);
}

HigeLayer* HigeLayer::create()
{
	auto instance = new HigeLayer();

	if (instance && instance->init())
	{
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}