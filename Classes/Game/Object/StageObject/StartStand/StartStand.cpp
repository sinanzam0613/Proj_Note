#include "StartStand.h"

USING_NS_CC;

StartStand* StartStand::create(const std::string textureName){

	auto obj = new StartStand();

	if (obj && obj->init(textureName)){
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;

}

bool StartStand::init(const std::string textureName){

	mSprite = Sprite::create(textureName);
	mSprite->setName("StartStand");
	addChild(mSprite);

	auto size = cocos2d::Size(mSprite->getContentSize().width, mSprite->getContentSize().height / 4);

	mSprite->setScale(0.6f);

	return true;

}

void StartStand::update(float deltatime){
	
}