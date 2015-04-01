#include "Goal.h"

USING_NS_CC;

Goal* Goal::create(const std::string textureName){

	auto obj = new Goal();

	if (obj && obj->init(textureName)){

		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;

}

bool Goal::init(const std::string textureName){
	mSprite = SpriteCreator::create(textureName);
	mSprite->retain();

	addChild(mSprite);

	return true;
}

void Goal::update(float deltatime){

}