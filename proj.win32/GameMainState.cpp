#include "GameMainState.h"

USING_NS_CC;

GameMainState* GameMainState::create(Layer* layer){

	auto obj = new GameMainState();

	if (obj && obj->init(layer)){
		obj->retain();
		obj->autorelease();
		return obj;
	}

	CC_SAFE_DELETE(obj);
	return nullptr;
}

bool GameMainState::init(Layer* layer){
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

void GameMainState::update(float at){

	(this->*updateFunc[mSceneState])(at);
}

void GameMainState::fadeIn(float at){
	if (mTestTouch){
		mTestTouch = false;
		mSceneState = MAIN;
	}
	auto obj = (Label*)parentLayer->getChildByName("ラベル");

	obj->setString("fadeIN");
}

void GameMainState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void GameMainState::fadeOut(float at){
	if (mTestTouch){
		mTestTouch = false;
		mSceneState = FADEIN;
	}
	auto obj = (Label*)parentLayer->getChildByName("ラベル");

	obj->setString("fadeOut");
}

void GameMainState::mainStart(float at){
	mUpdateState = UPDATELOOP;
}

void GameMainState::mainLoop(float at){
	if (mTestTouch){
		mTestTouch = false;
		mUpdateState = UPDATEEND;
	}
	auto obj = (Label*)parentLayer->getChildByName("ラベル");

	obj->setString("Loop");
}

void GameMainState::mainEnd(float at){
	mUpdateState = UPDATESTART;
	mSceneState = FADEOUT;
}

bool GameMainState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mTestTouch = true;

	return true;
}


void GameMainState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

}
