#include "TitleSpriteLayer.h"

USING_NS_CC;

/*--------------------------/
 コンストラクタ
 /--------------------------*/
TitleSpriteLayer::TitleSpriteLayer(){}

/*--------------------------/
 初期化
 /--------------------------*/
bool TitleSpriteLayer::init(){
    if(!Layer::init()){
        return false;
    }
    
    //初期描画
    fastDraw();
    
    return true;
}

/*--------------------------/
 初期描画
 /--------------------------*/
void TitleSpriteLayer::fastDraw(){
    //背景生成
    drawBackGraund();
    //タイトルロゴ描画
    drawTitleLogo();
    //タッチロゴ描画
    drawTouchLogo();
}



/*--------------------------/
 背景描画
/--------------------------*/
void TitleSpriteLayer::drawBackGraund(){
    auto BG = Sprite::create("Texture/GamePlay/GameScene/Title/Title_BackGround.png");
    BG->setPosition(Vec2(0,0));
    BG->setAnchorPoint(Vec2(0,0));
    addChild(BG);
}

/*--------------------------/
 タイトルロゴ描画
 /--------------------------*/
void TitleSpriteLayer::drawTitleLogo(){
    
    auto Touch = Sprite::create("Texture/GamePlay/GameScene/Title/Title_TitleLogo.png");
    Touch->setScale(0.8f, 0.9f);
    Touch->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2,
                             Director::getInstance()->getVisibleSize().height/2 + 200));
    Touch->setAnchorPoint(Vec2(0.5f,0.5f));
    Touch->setName("TitleLogo");
    addChild(Touch);
    
    
    auto mScaleUp = ScaleTo::create(1, 1.1f);
    auto mScaleDown = ScaleTo::create(1, 0.9f);
    auto sequence2 = Sequence::create(mScaleUp,mScaleDown,NULL);
    auto repeatForever2 = RepeatForever::create(sequence2);
    repeatForever2->setTag(13);
    repeatForever2->setTag(1);
    Touch->runAction(repeatForever2);
    
}

/*--------------------------/
 タッチロゴ描画
 /--------------------------*/
void TitleSpriteLayer::drawTouchLogo(){
    
    auto Logo = Sprite::create("Texture/GamePlay/GameScene/Title/Title_Touch.png");
    Logo->setScale(0.8f, 0.9f);
    Logo->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2,
                           Director::getInstance()->getVisibleSize().height/2 - 200));
    Logo->setAnchorPoint(Vec2(0.5f,0.5f));
    Logo->setOpacity(0);
    Logo->setName("TouchLogo");
    addChild(Logo);
    
    auto FadeIn = FadeIn::create(3);
    auto FadeOut = FadeOut::create(3);
    auto sequence = Sequence::create(FadeIn,FadeOut,NULL);
    auto repeatForever = RepeatForever::create(sequence);
    repeatForever->setTag(15);
    repeatForever -> setTag(0);
    Logo->runAction(repeatForever);
}


/*--------------------------/
クレジット描画
/--------------------------*/
void TitleSpriteLayer::drawCredit(){
    auto end = Sprite::create("Texture/GamePlay/GameScene/Title/Title_CreditSprite.png");
    end->setPosition(Vec2(0,0));
    end->setAnchorPoint(Vec2(0,0));
    addChild(end,100);
}

/*--------------------------/
 シーン生成
 /--------------------------*/
TitleSpriteLayer* TitleSpriteLayer::create()
{
    auto instance = new TitleSpriteLayer();
    
    if (instance && instance->init())
    {
        instance->autorelease();
        return instance;
    }
    
    CC_SAFE_DELETE(instance);
    return nullptr;
}

