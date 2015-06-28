#include "TitleActionLayer.h"

USING_NS_CC;

/*--------------------------/
 コンストラクタ
/--------------------------*/
TitleActionLayer::TitleActionLayer():
mselectCount(0)
{}


/*--------------------------/
 初期化
 /--------------------------*/
bool TitleActionLayer::init(){
    if(!Layer::init()){
        return false;
    }
    
    return true;
}

/*--------------------------/
 ボタン生成
/--------------------------*/
void TitleActionLayer::CreateButton(){
    ButtonCredit();
    ButtonStageselect();
    ButtonStart();
}

/*--------------------------/
 スタートボタン生成
/--------------------------*/
void TitleActionLayer::ButtonStart(){

    auto buttonImage = MenuItemImage::create("Texture/GamePlay/GameScene/Title/Title_Start.png",
										     "Texture/GamePlay/GameScene/Title/Title_Start.png",
                                       [ = ]( Ref* sender ){mselectCount = 1;});
    
    buttonImage->setPosition(Director::getInstance()->getVisibleSize().width/2,300);
    auto start = Menu::create( buttonImage, nullptr );
    start->setPosition( Vec2::ZERO );
    addChild(start);
}

/*--------------------------/
 ステージセレクトボタン生成
/--------------------------*/
void TitleActionLayer::ButtonStageselect(){

    auto buttonImage = MenuItemImage::create("Texture/GamePlay/GameScene/Title/Title_StageSelect.png",
                                             "Texture/GamePlay/GameScene/Title/Title_StageSelect.png",
                                             [ = ](Ref* sender){mselectCount = 2;}
                                             );
    
   
    buttonImage->setPosition(Director::getInstance()->getVisibleSize().width/2,200);
    auto stageSelect = Menu::create( buttonImage, nullptr );
    stageSelect->setPosition( Vec2::ZERO );
    this->addChild(stageSelect);
}

/*--------------------------/
 クレジットボタン生成
/--------------------------*/
void TitleActionLayer::ButtonCredit(){

    auto buttonImage = MenuItemImage::create("Texture/GamePlay/GameScene/Title/Title_Credit.png",
                                             "Texture/GamePlay/GameScene/Title/Title_Credit.png",
                                             [ = ](Ref* sender){mselectCount = 3;}
                                             );
    
    buttonImage->setPosition(Director::getInstance()->getVisibleSize().width/2,100);
    auto end = Menu::create( buttonImage, nullptr );
    end->setPosition( Vec2::ZERO );
    this->addChild(end);
}
/*--------------------------/
 クレジット生成
 /--------------------------*/
void TitleActionLayer::ButtonCreditSprite(){
    
    auto buttonImage = MenuItemImage::create("Texture/GamePlay/GameScene/Title/Title_CreditSprite.png",
                                             "Texture/GamePlay/GameScene/Title/Title_CreditSprite.png",
                                             [ = ](Ref* sender){mselectCount = 3;}
                                             );
    
    buttonImage->setPosition(Director::getInstance()->getVisibleSize().width/2,100);
    auto end = Menu::create( buttonImage, nullptr );
    end->setPosition( Vec2::ZERO );
    this->addChild(end);
}

/*--------------------------/
 状態取得
 /--------------------------*/
int TitleActionLayer::getSelectCount(){
    return mselectCount;
}

void TitleActionLayer::initSelectCount(){
    mselectCount = 0;
}

/*--------------------------/
 シーン生成
 /--------------------------*/
TitleActionLayer* TitleActionLayer::create()
{
    auto instance = new TitleActionLayer();
    
    if (instance && instance->init())
    {
        instance->autorelease();
        return instance;
    }
    
    CC_SAFE_DELETE(instance);
    return nullptr;
}

