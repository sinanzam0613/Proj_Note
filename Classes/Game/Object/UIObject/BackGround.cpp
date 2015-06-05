#include "BackGround.h"

USING_NS_CC;

/*--------------------------/
 コンストラクタ
/--------------------------*/
BackGround::BackGround(){
    
}

/*--------------------------/
 クリエイト
/--------------------------*/
BackGround* BackGround::create(){
    auto inst = new BackGround();
    
    if( inst &&  inst->init()){
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE(inst);
    return nullptr;
}

/*--------------------------/
 背景生成
/--------------------------*/
void BackGround::BackGraundCreate(Layer* layer){
    Sprite* mBG1;
    Sprite* mBG2;
    Sprite* mBG3;
    Sprite* mBG4;
    
    const float mSprightWeight = 1280;
    
    mBG1 = Sprite::create("Texture/GamePlay/GameStage/BackGround1.png");
    mBG1 -> setAnchorPoint(Vec2(0,0));
    mBG1 -> setPosition(Vec2(mSprightWeight,0));
    
    mBG2 = Sprite::create("Texture/GamePlay/GameStage/BackGround2.png");
    mBG2 -> setAnchorPoint(Vec2(0,0));
    mBG2 -> setPosition(Vec2(mSprightWeight * 2,0));
    
    mBG3 = Sprite::create("Texture/GamePlay/GameStage/BackGround3.png");
    mBG3 -> setAnchorPoint(Vec2(0,0));
    mBG3 -> setPosition(Vec2(mSprightWeight * 3,0));
    
    mBG4 = Sprite::create("Texture/GamePlay/GameStage/BackGround4.png");
    mBG4 -> setAnchorPoint(Vec2(0,0));
    mBG4 -> setPosition(Vec2(mSprightWeight * 4,0));
    
    
    
    layer -> addChild(mBG1,0);
}

