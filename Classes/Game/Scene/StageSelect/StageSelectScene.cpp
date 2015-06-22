#include "StageSelectScene.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"

/*--------------------------/
 コンストラクタ
/--------------------------*/
StageSelectScene::StageSelectScene(){
    
}


/*--------------------------/
 デストラクタ
/--------------------------*/
StageSelectScene::~StageSelectScene(){
    
}

/*--------------------------/
 シーン生成
/--------------------------*/
StageSelectScene* StageSelectScene::create(){
    auto inst = new StageSelectScene();
    
    if (inst && inst->init()){
        inst->autorelease();
        
        return inst;
    }
    
    CC_SAFE_DELETE(inst);
    return nullptr;
}

/*--------------------------/
 初期化
/--------------------------*/
bool StageSelectScene::init(){
    if(!Layer::init()){
        return false;
    }
    
    mState = StageSelectState::create(this);
    
    auto onTouchBegan = CC_CALLBACK_2(StageSelectScene::onTouchBegan, this);
    auto onTouchEnd = CC_CALLBACK_2(StageSelectScene::onTouchEnded, this);
    
    ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, onTouchEnd, nullptr);
    
    this->scheduleUpdate();
    
    return true;
}

void StageSelectScene::update(float at){
    mState->update(at);
}


bool StageSelectScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
    mState->onTouchBegan(touch, event);
    return true;
}


void StageSelectScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
    mState->onTouchEnded(touch, event);
}





