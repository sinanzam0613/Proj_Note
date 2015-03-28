#include "Bar.h"

USING_NS_CC;

Bar* Bar::create(const std::string textureName){

	auto obj = new Bar();

	if (obj && obj->init(textureName)){

		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;

}

bool Bar::init(const std::string textureName){
	mSprite = SpriteCreator::create(textureName);
	mSprite->retain();

	addChild(mSprite);

	return true;
}

void Bar::update(float deltatime){

}