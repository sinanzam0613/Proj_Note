#include "StartAnimation.h"
#include "Game/Scene/GameMain/Tags.h"

USING_NS_CC;

StartAnimation* StartAnimation::create(){
	auto obj = new StartAnimation();

	if (obj && obj->init()){
		obj->autorelease();

		return obj;
	}
	CC_SAFE_RELEASE(obj);

	return nullptr;
}


void StartAnimation::set(){ 
	auto size =	Director::getInstance()->getWinSize();

	auto sequens = createSequence();

	sequens->setTag(STARTACTION);

	addChild(createStartAnim(size,sequens));
}

Sprite* StartAnimation::createStartAnim(cocos2d::Size winSize,Sequence* action){
	auto sprite = Sprite::create("Texture/GamePlay/GameStage/Set.png");

	sprite->setTag(STARTSPRITE);
	sprite->setPosition(winSize / 2);
	sprite->setOpacity(0);

	sprite->runAction(action);

	return sprite;
}

Sequence* StartAnimation::createSequence(){
	auto fadeIn = FadeIn::create(2);

	auto delay = DelayTime::create(0.5f); //0.5秒、透明度最大のまま表示します。

	auto fadeOut = FadeOut::create(1);

	//スタート文字を追加します。
	auto go = CallFunc::create([&](){
		auto size = Director::getInstance()->getWinSize();
		auto startFade = FadeOut::create(2);
		auto start = Sprite::create("Texture/GamePlay/GameStage/Start.png");

		start->setPosition(size / 2);

		addChild(start);
		start->runAction(startFade);

	});

	return  Sequence::create(fadeIn, delay, fadeOut, go, nullptr);
}