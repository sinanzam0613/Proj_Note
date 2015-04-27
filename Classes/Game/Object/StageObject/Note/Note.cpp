#include "Note.h"
#include "Utility/Audio/ADX2Player.h"
#include "Utility/Audio/Define/PianoSample.h"

using namespace cocos2d;

Note::Note() {}

Note::~Note() {}

Note* Note::createObject(const cocos2d::Vec2 &position) {
	Note* instance = new Note();

	if (instance && instance->init(position)) {
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}

bool Note::init(const cocos2d::Vec2 &position) {
	if (!Node::init()) return false;
	

	mSprite = Sprite::create("Texture/GamePlay/Character/Note.png");
	mSprite->retain();
	this->addChild(mSprite);

	mSprite->setPosition(position);
	mSprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);

	mPhysicsBody = PhysicsBody::createBox(mSprite->getContentSize());
	mPhysicsBody->setMass(1.0f);
	mPhysicsBody->setDynamic(false);
	mPhysicsBody->setContactTestBitmask(true);
	mPhysicsBody->setCollisionBitmask(false);
	mPhysicsBody->setGravityEnable(false);

	mSprite->setPhysicsBody(mPhysicsBody);

	mSprite->setName("Note");
	Node::setName("Note");
	enableCollision("Note");

	mADX2Player = ADX2Player::create("Sound/ADX2/Sample_DoReMi.acb");
	mADX2Player->retain();

	return true;
}

void Note::update(float deltaTime) {}

void Note::soundPlay(int PosY) {
	if (PosY > 7) {
		PosY = 7;
	}
	mADX2Player->play(PosY);
}

void Note::onContactBegin(cocos2d::Node* contactNode){
	mADX2Player->play(1);
}

void Note::setName(const std::string& name){
	disableCollision(getName());
	
	mSprite->setName(name);
	Node::setName(name);

	enableCollision(name);
}