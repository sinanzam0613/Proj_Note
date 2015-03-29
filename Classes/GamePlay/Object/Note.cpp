#include "Note.h"

using namespace cocos2d;

Note::Note() {}

Note::~Note() {}

bool Note::init() {
	if (!Node::init()) return false;

	mSprite = Sprite::create("GamePlay/Character/Player.png");
	this->addChild(mSprite);

	return true;
}

void Note::update(float deltaTime) {}

Note* Note::createObject() {
	auto instance = new Note();

	if (instance && instance->init()) {
		instance->autorelease();
		return instance;
	}

	CC_SAFE_DELETE(instance);
	return nullptr;
}