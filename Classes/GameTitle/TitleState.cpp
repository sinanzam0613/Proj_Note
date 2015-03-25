#include "TitleState.h"

USING_NS_CC;

TitleState* TitleState::create(Layer* layer){

	auto obj = new TitleState();

	if (obj && obj->init(layer)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool TitleState::init(Layer* layer){
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

void TitleState::update(float at){
	
	(this->*updateFunc[mSceneState])(at);
}

void TitleState::fadeIn(float at){
	if (mTestTouch){
		mTestTouch = false;
		mSceneState = MAIN;
	}
	auto obj = (Label*)parentLayer->getChildByName("ラベル");

	obj->setString("fadeIN");
}

void TitleState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void TitleState::fadeOut(float at){
	if (mTestTouch){
		mTestTouch = false;
		mSceneState = FADEIN;
	}
	auto obj = (Label*)parentLayer->getChildByName("ラベル");

	obj->setString("fadeOut");
}

void TitleState::mainStart(float at){
	mUpdateState = UPDATELOOP;
}

void TitleState::mainLoop(float at){
	if (mTestTouch){
		mTestTouch = false;
		mUpdateState = UPDATEEND;
	}
	auto obj = (Label*)parentLayer->getChildByName("ラベル");

	obj->setString("Loop");
}

void TitleState::mainEnd(float at){
	mUpdateState =UPDATESTART;
	mSceneState = FADEOUT;
}

bool TitleState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mTestTouch = true;

	return true;
}


void TitleState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

}
