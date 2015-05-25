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
    Sprite* mBG;
    
    mBG = Sprite::create("Texture/GamePlay/Character/BG.png");
    mBG -> setAnchorPoint(Vec2(0,0));
    mBG -> setPosition(Vec2(0,0));
    
    layer -> addChild(mBG,0);
}

