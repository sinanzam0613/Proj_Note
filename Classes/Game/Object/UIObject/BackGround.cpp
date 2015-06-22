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
    Sprite* BG;
    
    //const float mSprightWeight = 1800;
    
    BG = Sprite::create("Texture/GamePlay/GameStage/BackGround.png");
    BG -> setAnchorPoint(Vec2(0,0));
    BG -> setPosition(Vec2(0,0));
    
    layer -> addChild(BG,0);
}

