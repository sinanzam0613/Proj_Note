#include "Note.h"
#include "Utility/Audio/ADX2Player.h"
#include "Utility/Audio/Define/Sample_DoReMi.h"

using namespace cocos2d;

Note::Note() {}

Note::~Note() {}

bool Note::init() {
	if (!Node::init()) return false;
	mSprite = Sprite::create("GamePlay/Character/Note.png");
	
	auto afa = mSprite->getContentSize().height;
	this->setContentSize(Size(mSprite->getContentSize().width, mSprite->getContentSize().height * 2));
	//mSprite->setAnchorPoint(Vec2(0, 0));
	setAnchorPoint(Vec2(0.5f, 0));
	PhysicsBody* body = PhysicsBody::createBox(this->getContentSize());
	body->setMass(1.0f);
	mSprite->setPhysicsBody(body);
	this->addChild(mSprite);

	mADX2Player = ADX2Player::create("Sound/ADX2/Sample_DoReMi.acb");
	mADX2Player->retain();

	return true;
}

void Note::update(float deltaTime) {}

void Note::SoundPlay(int PosY) {
	if (PosY > 7) {
		PosY = 7;
	}
	mADX2Player->play(PosY);
}

Note* Note::createObject() {
	auto instance = new Note();

	if (instance && instance->init()) {
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}

void Note::setPosition(const Vec2& pos){
	//mSprite->setPosition(pos);
	Node::setPosition(pos);
}