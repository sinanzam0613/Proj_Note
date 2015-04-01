#include "HigeLayer.h"
#include "Game/Object/StageObject/Note/Note.h"
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
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255), 1280, 720)) return false;

	this->schedule(schedule_selector(HigeLayer::update));

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HigeLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HigeLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HigeLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	noteCreator();
	auto back = Sprite::create("GamePlay/Character/NoteLine.png");
	back->setAnchorPoint(Vec2(0,0));
	addChild(back);

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
	if (mMoveNote > 7) return;
	auto pNote = this->getChildByTag(mMoveNote);
	pNote->setPositionY(pos.y);
}

void HigeLayer::onTouchEnded(Touch* touch, Event* event) {
	if (mMoveNote > 7) return;
	Note* pNote = static_cast<Note*>(this->getChildByTag(mMoveNote));
	int setLinePos = 0;
	setLinePos = (int)pNote->getPositionY() / 100;
	pNote->SoundPlay(setLinePos);
	setLinePos = setLinePos * 150;
	pNote->setPositionY(setLinePos);
	mMoveNote = 8;
}

void HigeLayer::noteCreator() {
	for (int i = 0; i < 5; ++i) {
		auto note = Note::createObject();
		note->setPosition(Vec2(100 + i * 130, rand() % 500 + 300));
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