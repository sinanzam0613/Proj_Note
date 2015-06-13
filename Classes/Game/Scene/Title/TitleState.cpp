#include "TitleState.h"
#include "cocos-ext.h"
#include "Utility/Audio/ADX2Player.h"


USING_NS_CC;
using namespace cocos2d::extension;

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

/*-----------------------------------------------------
 -------初期化
 -----------------------------------------------------*/
bool TitleState::init(Layer* layer){
	mSceneState = FADEIN;
	mUpdateState = UPDATESTART;
	parentLayer = layer;
	mTestTouch = false;
    
    mTitleSpriteLayer = TitleSpriteLayer::create();
    layer->addChild(mTitleSpriteLayer);
    
	return true;
}

/*-----------------------------------------------------
  -------更新
 -----------------------------------------------------*/
void TitleState::update(float at){(this->*updateFunc[mSceneState])(at);}


/*-----------------------------------------------------
 -------フェードイン
 -----------------------------------------------------*/
void TitleState::fadeIn(float at){
	if (mTestTouch){
		mTestTouch = false;
		mSceneState = MAIN;
	}
}

/*-----------------------------------------------------
 -------シーンメイン
 -----------------------------------------------------*/
void TitleState::sceneMain(float at){(this->*mainFunc[mUpdateState])(at);}

/*-----------------------------------------------------
 -------フェードアウト
 -----------------------------------------------------*/
void TitleState::fadeOut(float at){
	if (mTestTouch){
		mTestTouch = false;
		mSceneState = FADEIN;
	}
    
    
}

/*-----------------------------------------------------
 -------シーンメイン（スタート）
 -----------------------------------------------------*/
void TitleState::mainStart(float at){mUpdateState = UPDATELOOP;}

/*-----------------------------------------------------
 -------シーンメイン（ループ）
 -----------------------------------------------------*/
void TitleState::mainLoop(float at){
	if (mTestTouch){
		mTestTouch = false;
		mUpdateState = UPDATEEND;
	}
    
    
}
/*-----------------------------------------------------
 -------シーンメイン（エンド）
 -----------------------------------------------------*/
void TitleState::mainEnd(float at){
	mUpdateState =UPDATESTART;
	mSceneState = FADEOUT;
}

bool TitleState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
	mTestTouch = true;
    
    //アクションの停止
    auto touchLogo = mTitleSpriteLayer->getChildByName("TouchLogo");
    touchLogo->stopAllActions();
    touchLogo->setOpacity(0);
    auto titleLogo = mTitleSpriteLayer->getChildByName("TitleLogo");
    titleLogo->stopAllActions();
    titleLogo->setOpacity(0);
    
    
        
    mTitleSpriteLayer->nextDraw();

    
	return true;
}


void TitleState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){

}
