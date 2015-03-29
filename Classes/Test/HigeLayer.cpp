#include "HigeLayer.h"
#include "GamePlay/Object/Note.h"
#include "Utility/Audio/ADX2Player.h"
#include "Utility/Audio/Define/Sample_DoReMi.h"
#include <math.h>
#include <random>

using namespace cocos2d;

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()

HigeLayer::HigeLayer() 
	: mADX2Player(nullptr)
	, mMoveNote(NULL) {
	//目る専ぬツイスター
	srand((unsigned)time(NULL));
}

HigeLayer::~HigeLayer() {
	for ( int i = 0; i < mNoteContainar.size(); ++i) {
		mNoteContainar[i]->release();
	}
	mNoteContainar.clear();
}

bool HigeLayer::init() {
	if (!Layer::init()) return false;

	this->schedule(schedule_selector(HigeLayer::update));

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HigeLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HigeLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HigeLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	noteCreator();
	return true;
}

void HigeLayer::update(float deltaTime) {}


bool HigeLayer::onTouchBegan(Touch* touch, Event* event) {
	Point pos = this->convertTouchToNodeSpace(touch);
	for (int i = 0; i < mNoteContainar.size(); ++i) {
		auto pNote = this->getChildByTag(i);
		if (!pNote) {
			return false;
		}
		Rect noteRect = pNote->boundingBox();
		if (noteRect.containsPoint(pos)) {
			mMoveNote = i;
			return true;
		}
	}
	return true;
}

void HigeLayer::onTouchMoved(Touch* touch, Event* event) {
	Point pos = this->convertTouchToNodeSpace(touch);
	auto pNote = this->getChildByTag(mMoveNote);
	pNote->setPositionY(pos.y);
}

void HigeLayer::onTouchEnded(Touch* touch, Event* event) {
	Note* pNote = static_cast<Note*>(this->getChildByTag(mMoveNote));
	int setLinePos = 0;
	setLinePos = (int)pNote->getPositionY() / 100;
	pNote->SoundPlay(setLinePos);
	setLinePos = setLinePos * 150;
	pNote->setPositionY(setLinePos);
}

void HigeLayer::noteCreator() {
	for (int i = 0; i < 5; ++i) {
		auto note = Note::createObject();
		note->setPosition(100 + i * 130, rand() % 500 + 300);
		note->setTag(i);
		note->retain();
		mNoteContainar.push_back(note);
		this->addChild(note);
	}
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