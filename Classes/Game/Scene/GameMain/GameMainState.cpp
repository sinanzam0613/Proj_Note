#include "GameMainState.h"
#include "Utility/Collision/PhysicsListener.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Scene/GameMain/GameDataMediator.h"

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

	auto back = Sprite::create("Texture/GamePlay/GameStage/BackGround1.png");
	back->setAnchorPoint(Vec2(0, 0));
	back->setPosition(Vec2(0, 5));
	parentLayer->addChild(back);

	auto mediator = GameDataMediator::create();
	mediator->setTag(12345);
	parentLayer->addChild(mediator);

	mediator->setFollow(parentLayer);

	auto lis = PhysicsListener::create();
	parentLayer->addChild(lis);

	uiLayer = UiObjectLayer::create();

	parentLayer->addChild(uiLayer);

	return true;
}

void GameMainState::update(float at){

	(this->*updateFunc[mSceneState])(at);
}

void GameMainState::fadeIn(float at){
	mSceneState = MAIN;
}

void GameMainState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void GameMainState::fadeOut(float at){
	
	mSceneState = FADEIN;	
}

void GameMainState::mainStart(float at){
	mUpdateState = UPDATELOOP;
}

void GameMainState::mainLoop(float at){

	mSlideBar->setPosition(Vec2(parentLayer->getPosition().x, parentLayer->getPosition().y), uiLayer);

	auto media = (GameDataMediator*)parentLayer->getChildByTag(12345);

	media->update(at, uiLayer);
	
}

void GameMainState::mainEnd(float at){
	mUpdateState = UPDATESTART;
	mSceneState = FADEOUT;
}

bool GameMainState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){

	return true;
}


void GameMainState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

}
