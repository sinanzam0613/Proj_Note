#include "GameMainScene.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"

GameMainScene::GameMainScene()
{
}


GameMainScene::~GameMainScene()
{
	mState->release();
    ply->release();
}

GameMainScene* GameMainScene::create(){
	auto obj = new GameMainScene();

	if (obj && obj->init()){
		obj->autorelease();

		return obj;
	}

	CC_SAFE_DELETE(obj);

	return nullptr;
}

bool GameMainScene::init(){
	if (!Layer::init())
	{
		return false;
	}

	mState = GameMainState::create(this);

	auto onTouchBegan = CC_CALLBACK_2(GameMainScene::onTouchBegan, this);
	auto onTouchEnd = CC_CALLBACK_2(GameMainScene::onTouchEnded, this);

	ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, onTouchEnd, nullptr);
    
    auto node = Node::create();
    auto func = cocos2d::CallFunc::create([&]() {
        ply = ADX2Player::create("Sound/ADX2/MusicUnit/BackMusic.acb");
        ply->play(0);
        ply->retain();
    });
    auto delay = cocos2d::DelayTime::create(1.6f);
    auto seq = cocos2d::Sequence::create(delay, func, nullptr);
    node->runAction(seq);
    this->addChild(node);

	this->scheduleUpdate();

	return true;
}

void GameMainScene::update(float at){
	mState->update(at);
}


bool GameMainScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchBegan(touch, event);
	return true;
}


void GameMainScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
	mState->onTouchEnded(touch, event);
}