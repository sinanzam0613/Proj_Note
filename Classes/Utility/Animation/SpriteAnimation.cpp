#include "SpriteAnimation.h"

using namespace Util;
USING_NS_CC;

SpriteAnimation::SpriteAnimation(const std::string& path){
	mResourcePath = path;
}


Sprite* SpriteAnimation::create(const std::string& spriteName, const int count, const float delay, const bool restart, const bool repeat){
	
	std::string textureName = spriteName;

	Sprite* firstSprite = Sprite::create(mResourcePath + textureName + "1.png");
	firstSprite->setName(spriteName);

	auto animation = Animation::create();
	for (int i = 2; i <= count; ++i){
		animation->addSpriteFrameWithFile(mResourcePath + textureName + std::to_string(i) + ".png");
	}
	animation->setRestoreOriginalFrame(restart);
	animation->setDelayPerUnit(delay);

	//繰り返すなら
	if (repeat){
		Animate* animate = Animate::create(animation);
		RepeatForever* repeatTrue = RepeatForever::create(animate);
		firstSprite->runAction(repeatTrue);
	}

	return firstSprite;
}

void SpriteAnimation::setResourcesPath(const std::string& path){
	mResourcePath = path;
}