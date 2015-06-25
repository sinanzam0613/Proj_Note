#include "GameMainState.h"
#include "Utility/Collision/PhysicsListener.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Scene/GameMain/GameDataMediator.h"
#include "Game/Object/UIObject/BackGround.h"
#include "Game/Scene/GameMain/Tags.h"
#include "Game/Object/StageObject/StartStand/StartStand.h"
#include "PauseBotton.h"
#

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
    
    
	auto mediator = GameDataMediator::create();
	mediator->setTag(12345);
	parentLayer->addChild(mediator);

	mediator->setFollow(parentLayer);

	auto lis = PhysicsListener::create();
	parentLayer->addChild(lis);

	uiLayer = UiObjectLayer::create();

	parentLayer->addChild(uiLayer);

	auto back = BackGround::create(parentLayer);
	back->setTag(1004);
	parentLayer->addChild(back);

	auto startStand = StartStand::create("Texture/GamePlay/GameStage/StartBlockAfter.png");
	startStand->setName("StartStand");
	startStand->setPosition(Vec2(140, 200));

	parentLayer->addChild(startStand);

	createPauseBotton();

	return true;
}

void GameMainState::update(float at){

	(this->*updateFunc[mSceneState])(at);
}

void GameMainState::fadeIn(float at){

	auto start = StartAnimation::create();
	parentLayer->addChild(start);
	start->setTag(STARTNODE);
	start->set();

	mSceneState = MAIN;
}

void GameMainState::sceneMain(float at){
	(this->*mainFunc[mUpdateState])(at);
}

void GameMainState::fadeOut(float at){
	
	mSceneState = FADEIN;	
}

void GameMainState::mainStart(float at){
	auto startAction =  (Sequence*)parentLayer->getChildByTag(STARTNODE)->getChildByTag(STARTSPRITE)->getActionByTag(STARTACTION);
	

	if (!startAction){
		mUpdateState = UPDATELOOP;
	}
}

void GameMainState::mainLoop(float at){

	uiLayer->setPosition(parentLayer->getPosition() * -1);

	auto media = (GameDataMediator*)parentLayer->getChildByTag(12345);

	media->update(at, uiLayer);

	auto back = (BackGround*)parentLayer->getChildByTag(1004);
	back->update(at, parentLayer);
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

void GameMainState::createPauseBotton(){
	auto normalSprite = Sprite::create("Texture/GamePlay/Character/2Rest.png");

	auto selectSprite = Sprite::create("Texture/GamePlay/Character/2Rest.png");

	auto pause = UI::PauseBotton::create(normalSprite, selectSprite);

	auto size = cocos2d::Director::getInstance()->getWinSize();

	auto menu = Menu::create(pause, nullptr);
	menu->setPosition(Vec2(size.width - (normalSprite->getContentSize().width / 2),
		size.height - normalSprite->getContentSize().height));

	uiLayer->addChild(menu);
}
