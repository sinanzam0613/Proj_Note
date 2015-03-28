#include "EndingScene.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"

EndingScene::EndingScene()
{
}


EndingScene::~EndingScene()
{
	mState->release();
}

EndingScene* EndingScene::create(){
	auto obj = new EndingScene();

	if (obj && obj->init()){
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;
}

bool EndingScene::init(){
	if (!Layer::init())
	{
		return false;
	}

	mState = EndingState::create(this);

	auto onTouchBegan = CC_CALLBACK_2(EndingScene::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(EndingScene::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, onTouchEnd, nullptr);

	this->scheduleUpdate();

	return true;
}

void EndingScene::update(float at){
	mState->update(at);
}


bool EndingScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchBegan(touch, event);
	return true;
}


void EndingScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchEnded(touch, event);
}