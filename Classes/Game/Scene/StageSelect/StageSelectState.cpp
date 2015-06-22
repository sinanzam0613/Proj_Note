#include "StageSelectState.h"
USING_NS_CC;

StageSelectState* StageSelectState::create(Layer* layer){
    
    auto obj = new StageSelectState();
    
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
bool StageSelectState::init(Layer* layer){
    mSceneState = FADEIN;
    mUpdateState = UPDATESTART;
    parentLayer = layer;
    mTestTouch = false;
    
    mStageSelectSpriteLayer = StageSelectSpriteLayer::create();
    layer->addChild(mStageSelectSpriteLayer);
    
    mStageSelectActionLayer = StageSelectActionLayer::create();
    layer->addChild(mStageSelectActionLayer);
    
    return true;
}

/*-----------------------------------------------------
 -------更新
 -----------------------------------------------------*/
void StageSelectState::update(float at){(this->*updateFunc[mSceneState])(at);}


/*-----------------------------------------------------
 -------フェードイン
 -----------------------------------------------------*/
void StageSelectState::fadeIn(float at){
    if (mTestTouch){
        mTestTouch = false;
        mSceneState = MAIN;
    }
}

/*-----------------------------------------------------
 -------シーンメイン
 -----------------------------------------------------*/
void StageSelectState::sceneMain(float at){(this->*mainFunc[mUpdateState])(at);}

/*-----------------------------------------------------
 -------フェードアウト
 -----------------------------------------------------*/
void StageSelectState::fadeOut(float at){
    if (mTestTouch){
        mTestTouch = false;
        mSceneState = FADEIN;
    }
}

/*-----------------------------------------------------
 -------シーンメイン（スタート）
 -----------------------------------------------------*/
void StageSelectState::mainStart(float at){mUpdateState = UPDATELOOP;}

/*-----------------------------------------------------
 -------シーンメイン（ループ）
 -----------------------------------------------------*/
void StageSelectState::mainLoop(float at){
    if (mTestTouch){
        mTestTouch = false;
        mUpdateState = UPDATEEND;
    }
}

/*-----------------------------------------------------
 -------シーンメイン（エンド）
 -----------------------------------------------------*/
void StageSelectState::mainEnd(float at){
    mUpdateState =UPDATESTART;
    mSceneState = FADEOUT;
}

bool StageSelectState::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
    mTestTouch = true;
    
    return true;
}


void StageSelectState::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
    
}
