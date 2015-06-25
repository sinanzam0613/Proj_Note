#include "CreditScene.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "Game/Scene/Title/TitleScene.h"
#include "Game/Scene/GameMain/ResultLayer.h"

USING_NS_CC;

CreditScene::CreditScene()
{
}


CreditScene::~CreditScene()
{
}

CreditScene* CreditScene::create(){
    auto obj = new CreditScene();
    
    if (obj && obj->init()){
        obj->autorelease();
        
        return obj;
    }
    
    CC_SAFE_DELETE(obj);
    
    return nullptr;
}

bool CreditScene::init(){
    if (!Layer::init())
    {
        return false;
    }
    
 
    

    auto onTouchBegan = CC_CALLBACK_2(CreditScene::onTouchBegan, this);
    auto onTouchEnd = CC_CALLBACK_2(CreditScene::onTouchEnded, this);
    
    ListenerAssistant::setupSingleTouchListener(this, true, onTouchBegan, nullptr, onTouchEnd, nullptr);
    
    this->scheduleUpdate();
    
    
    auto BG = cocos2d::Sprite::create("Texture/GamePlay/GameScene/Credit.png");
    BG->setPosition(cocos2d::Vec2(0,0));
    BG->setAnchorPoint(cocos2d::Vec2(0,0));
    addChild(BG);
    
    return true;
}

void CreditScene::update(float at){
  
}


bool CreditScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event){
    
    auto nextScene = SceneCreator::createScene(TitleScene::create());
    auto scene	= TransitionFade::create( 1.5f, nextScene, Color3B::BLACK );
    auto dir = Director::getInstance();
    dir->replaceScene(scene);
    
    return true;
}


void CreditScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event){
}