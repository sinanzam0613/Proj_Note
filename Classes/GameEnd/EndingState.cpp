#include "EndingState.h"

USING_NS_CC;

EndingState* EndingState::create(Layer* layer){

	auto obj = new EndingState();

	if (obj && obj->init(layer)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool EndingState::init(Layer* layer){
	mSceneState = FADEIN;
	mUpdateState = UPDATESTART;
	parentLayer = layer;
	mTestTouch = false;

	auto debugLabel = Label::createWithTTF("TitleScreen", "Font/MarkerFelt.ttf", 64);
	debugLabel->setName("ラベル");
	debugLabel->setPosition(Vec2(500, 500));
	parentLayer->addChild(debugLabel);

	return true;
}

void EndingState::update(float at){

	(this->*updateFunc[mSceneState])(at);
}

void EndingState::fadeIn(float at){
	if (mTestTouch){
		mTestTouch = false;
		mSceneState = MAIN;
	}
	auto obj = (Label*)parentLayer->getChildByName("ラベル");

	obj->setString("fadeIN");
}

void EndingState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void EndingState::fadeOut(float at){
	if (mTestTouch){
		mTestTouch = false;
		mSceneState = FADEIN;
	}
	auto obj = (Label*)parentLayer->getChildByName("ラベル");

	obj->setString("fadeOut");
}

void EndingState::mainStart(float at){
	mUpdateState = UPDATELOOP;
}

void EndingState::mainLoop(float at){
	if (mTestTouch){
		mTestTouch = false;
		mUpdateState = UPDATEEND;
	}
	auto obj = (Label*)parentLayer->getChildByName("ラベル");

	obj->setString("Loop");
}

void EndingState::mainEnd(float at){
	mUpdateState = UPDATESTART;
	mSceneState = FADEOUT;
}

bool EndingState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mTestTouch = true;

	return true;
}


void EndingState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

}
