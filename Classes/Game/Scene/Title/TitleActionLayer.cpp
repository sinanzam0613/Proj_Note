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
    ButtonEnd();
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
    
    buttonImage->setPosition(300,100);
    auto start = Menu::create( buttonImage, nullptr );
    start->setPosition( Vec2::ZERO );
    this->addChild(start);
}

/*--------------------------/
 ステージセレクトボタン生成
/--------------------------*/
void TitleActionLayer::ButtonStageselect(){

    auto buttonImage = MenuItemImage::create("Texture/GamePlay/GameScene/Title/Title_StageSelect.png",
                                             "Texture/GamePlay/GameScene/Title/Title_StageSelect.png",
                                             [ = ](Ref* sender){mselectCount = 2;}
                                             );
    
   
    buttonImage->setPosition(800,100);
    auto stageSelect = Menu::create( buttonImage, nullptr );
    stageSelect->setPosition( Vec2::ZERO );
    this->addChild(stageSelect);
}

/*--------------------------/
 終了ボタン生成
/--------------------------*/
void TitleActionLayer::ButtonEnd(){

    auto buttonImage = MenuItemImage::create("Texture/GamePlay/GameScene/Title/Title_End.png",
                                             "Texture/GamePlay/GameScene/Title/Title_End.png",
                                             [ = ](Ref* sender){mselectCount = 3;}
                                             );
    
    buttonImage->setPosition(1200,100);
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

