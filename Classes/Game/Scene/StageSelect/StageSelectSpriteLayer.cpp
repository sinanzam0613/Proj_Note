#include "StageSelectSpriteLayer.h"

USING_NS_CC;

/*--------------------------/
 コンストラクタ
/--------------------------*/
StageSelectSpriteLayer::StageSelectSpriteLayer(){
    
}

/*--------------------------/
 デストラクタ
/--------------------------*/
StageSelectSpriteLayer::~StageSelectSpriteLayer(){
    
}


/*--------------------------/
 初期化
/--------------------------*/
bool StageSelectSpriteLayer::init(){
    
    if(!Layer::init()){
        return false;
    }
    
    drawBackGround();
    drawLogo();

    
    return true;
}

/*--------------------------/
 背景描画
 /--------------------------*/
void StageSelectSpriteLayer::drawBackGround(){
    auto BG = Sprite::create("Texture/GamePlay/GameScene/StageSelect/StageSelect_BackGround.png");
    BG->setPosition(Vec2(0,0));
    BG->setAnchorPoint(Vec2(0,0));
    this->addChild(BG,0);
}

/*--------------------------/
 タイトル描画
 /--------------------------*/
void StageSelectSpriteLayer::drawLogo(){
    auto Logo = Sprite::create("Texture/GamePlay/GameScene/StageSelect/StageSelect_Logo.png");
    Logo->setPosition(Vec2(250,550));
    Logo->setAnchorPoint(Vec2(0,0));
    this->addChild(Logo);
}


/*--------------------------/
 シーン生成
 /--------------------------*/
StageSelectSpriteLayer* StageSelectSpriteLayer::create()
{
    auto instance = new StageSelectSpriteLayer();
    
    if (instance && instance->init())
    {
        instance->autorelease();
        return instance;
    }
    
    CC_SAFE_DELETE(instance);
    return nullptr;
}

