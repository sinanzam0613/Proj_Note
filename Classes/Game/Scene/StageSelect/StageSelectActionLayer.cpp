#include "StageSelectActionLayer.h"
USING_NS_CC;

/*--------------------------/
 コンストラクタ
 /--------------------------*/
StageSelectActionLayer::StageSelectActionLayer(){
    
}

/*--------------------------/
 デストラクタ
 /--------------------------*/
StageSelectActionLayer::~StageSelectActionLayer(){
    
}


/*--------------------------/
 初期化
/--------------------------*/
bool StageSelectActionLayer::init(){
    
    if(!Layer::init()){
        return false;
    }
    
    buttonBack();
    
    buttonStage();
    
    return true;
}

/*--------------------------/
 戻るボタン生成
/--------------------------*/
void StageSelectActionLayer::buttonBack(){
    auto buttonImage = MenuItemImage::create("Texture/GamePlay/GameScene/StageSelect/StageSelect_Back.png",
                                             "Texture/GamePlay/GameScene/StageSelect/StageSelect_Back.png",
                                             [ = ](Ref* sender)
                                            {
                                             
                                             
                                             });
    
    
    buttonImage->setPosition(1150,650);
    auto stageSelect = Menu::create( buttonImage, nullptr );
    stageSelect->setPosition( Vec2::ZERO );
    this->addChild(stageSelect,0);
}

/*--------------------------/
 ステージボタン生成
 /--------------------------*/
void StageSelectActionLayer::buttonStage(){
    
    
    auto menu = Menu::create();
    menu->setPosition( Vec2::ZERO );
    menu->setName( "Unko" );
    this->addChild( menu );
    
    auto unko = [ this, &menu ](const std::string& normal, const std::string& selected, const Vec2& pos, std::function < void( Ref* ) > func)
    {
       auto a = MenuItemImage::create("Texture/GamePlay/GameScene/StageSelect/" + normal + ".png",
                                      "Texture/GamePlay/GameScene/StageSelect/" + selected + ".png",
                                      func);
        
        
        a->setPosition(pos);
        a->setScale(0.6f);
        menu->addChild( a );
        
    };
    
    //ステージボタン生成
    unko("StageSelect_Stage1","StageSelect_Stage1",Vec2( 200, 450), [ this ]( Ref* ){ this->stageSelected(1);});
    unko("StageSelect_Stage2","StageSelect_Stage2",Vec2( 500, 450), [ this ]( Ref* ){ this->stageSelected(2);});
    unko("StageSelect_Stage3","StageSelect_Stage3",Vec2( 800, 450), [ this ]( Ref* ){ this->stageSelected(3);});
    unko("StageSelect_Stage4","StageSelect_Stage4",Vec2(1100, 450), [ this ]( Ref* ){ this->stageSelected(4);});
    unko("StageSelect_Stage5","StageSelect_Stage5",Vec2( 200, 250), [ this ]( Ref* ){ this->stageSelected(5);});
    unko("StageSelect_Stage6","StageSelect_Stage6",Vec2( 500, 250), [ this ]( Ref* ){ this->stageSelected(6);});
    unko("StageSelect_Stage7","StageSelect_Stage7",Vec2( 800, 250), [ this ]( Ref* ){ this->stageSelected(7);});
    unko("StageSelect_Stage8","StageSelect_Stage8",Vec2(1100, 250), [ this ]( Ref* ){ this->stageSelected(8);});
}

/*--------------------------/
 ステージ選択時
/--------------------------*/
void StageSelectActionLayer::stageSelected(int tag){
    
    //ローカルレイヤー生成
    auto layer = Layer::create();
    
    //メニュー母体生成
    auto menu = Menu::create();
    menu->setPosition( Vec2::ZERO );
    //layer->addChild(menu);
    
    //各自追加
    drawMask(layer);
    drawExplain(layer);
    buttonYes(layer,menu);
    buttonNo(layer,menu);
    
    layer->addChild(menu);
    
    //タッチの無効化
    isButton(false);
    
    //レイヤーに追加
    this->addChild(layer);
}

/*--------------------------/
 Mask描画
/--------------------------*/
void StageSelectActionLayer::drawMask(Layer* layer){
    //マスク生成
    auto mask = Sprite::create("Texture/GamePlay/GameScene/StageSelect/StageSelect_Mask.png");
    mask->setPosition(Vec2(0,100));
    mask->setAnchorPoint(Vec2(0,0));
    layer->addChild(mask);


}

/*--------------------------/
 ロゴ描画
/--------------------------*/
void StageSelectActionLayer::drawExplain(Layer* layer){
    //確認生成
    auto explainLogo = Sprite::create("Texture/GamePlay/GameScene/StageSelect/StageSelect_Check.png");
    explainLogo->setPosition(Vec2(250,500));
    explainLogo->setScale(1.2f);
    explainLogo->setAnchorPoint(Vec2(0,0));
    layer->addChild(explainLogo);
    
}

/*--------------------------/
 Yesボタン生成
 /--------------------------*/
void StageSelectActionLayer::buttonYes(cocos2d::Layer* layer,Menu* menu){
    
    auto buttonYes = MenuItemImage::create("Texture/GamePlay/GameScene/StageSelect/StageSelect_Yes.png",
                                           "Texture/GamePlay/GameScene/StageSelect/StageSelect_Yes.png",
                                           [ = ](Ref* sender)
                                           {
                                               
                                           }
                                           );
    buttonYes->setPosition(400,300);
    buttonYes->setScale(1.2f);
    menu->addChild(buttonYes);
    
}

/*--------------------------/
 Noボタン生成
/--------------------------*/
void StageSelectActionLayer::buttonNo(cocos2d::Layer* layer,Menu* menu){
    auto buttonNo = MenuItemImage::create("Texture/GamePlay/GameScene/StageSelect/StageSelect_No.png",
                                          "Texture/GamePlay/GameScene/StageSelect/StageSelect_No.png",
                                          [ = ](Ref* sender)
                                          {
                                              layer->removeFromParent();
                                        
                                              isButton(true);
                                              
                                          }
                                          );
    buttonNo->setPosition(900,300);
    buttonNo->setScale(1.2f);
    menu->addChild(buttonNo);
}

/*--------------------------/
 ボタン有効無効切り替え
/--------------------------*/
void StageSelectActionLayer::isButton(bool flag){
    auto menu =  static_cast< MenuItem* > ( this->getChildByName( "Unko" ) );
    for ( auto& child : menu->getChildren() )
    {
        static_cast< MenuItem* >( child )->setEnabled( flag );
    }
}




/*--------------------------/
 シーン生成
 /--------------------------*/
StageSelectActionLayer* StageSelectActionLayer::create()
{
    auto instance = new StageSelectActionLayer();
    
    if (instance && instance->init())
    {
        instance->autorelease();
        return instance;
    }
    
    CC_SAFE_DELETE(instance);
    return nullptr;
}

