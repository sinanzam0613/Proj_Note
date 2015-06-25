#include "ResultLayer.h"
#include "../GameMain/GameMainScene.h"
#include "Game/Scene/Title/TitleScene.h"
#include "../../../Utility/SceneSupport/SceneCreator.h"


using namespace cocos2d;

ResultLayer::ResultLayer()
{
    
}

ResultLayer::~ResultLayer()
{
    stopAllActions();
}

ResultLayer* ResultLayer::create(Vec2 pos)
{
    auto inst = new ResultLayer();
    
    if ( inst && inst->init(pos) )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

bool ResultLayer::init(Vec2 pos)
{
    if ( !LayerColor::initWithColor( Color4B::BLACK ) )
    {
        return false;
    }
    
    selectScene(pos);
  
    
    return true;
}

void ResultLayer::selectScene(Vec2 pos){
    auto continueCallback = [&](Ref*) { Director::getInstance()->popScene(); };
    
    auto nextCallback		= [ & ]( Ref* )
    {
        auto userDef = UserDefault::getInstance();
        int  selectStage  = userDef -> getIntegerForKey("selectStage");
        int  clearStage = userDef -> getIntegerForKey("clearStage");
        
        if( clearStage <  selectStage )
        {
            userDef->setIntegerForKey("clearStage",selectStage);
            userDef->flush();
        }
        
        auto scene = SceneCreator::createPhysicsScene(GameMainScene::create(), Vect(0, -9.8f), 5.0f, true);
        auto fade	= TransitionFade::create( 1.5f, scene, Color3B::BLACK );
        Director::getInstance()->replaceScene( fade );
    };
    
    auto titleCallback		= [ & ]( Ref* )
    {
        auto scene = SceneCreator::createPhysicsScene(GameMainScene::create(), Vect(0, -9.8f), 5.0f, true);
        auto fade	= TransitionFade::create( 1.5f, scene, Color3B::BLACK );
        Director::getInstance()->replaceScene( fade );
    };
    
    auto icon = Sprite::create( "Texture/GamePlay/GameScene/Pause/Pause_Logo.png" );
    icon->setPosition( Vec2( 1190, 696 ) );
    
    auto BG = Sprite::create("Texture/GamePlay/GameScene/StageSelect/StageSelect_Mask.png");
    BG->setPosition(Vec2(pos.x,pos.y));
    BG->setScale(3.0f,3.0f);
    BG->setAnchorPoint(Vec2(0.5f,0.5f));
    addChild(BG);
    
    putButton( "Pause_Continue.png",	"Pause_Continue.png",	Vec2(pos.x, pos.y + 200 ), continueCallback	);
    putButton( "Pause_ReStart.png",		"Pause_ReStart.png",	Vec2(pos.x, pos.y       ), nextCallback		);
    putButton( "Pause_End.png",			"Pause_End.png",		Vec2(pos.x, pos.y - 200  ), titleCallback     );
    
   
    
}

void ResultLayer::putButton( const std::string& normal, const std::string& selected, const Vec2& position, ButtonCallback callback )
{
    const auto path = "Texture/GamePlay/GameScene/Pause/";
    
    auto buttonImg = MenuItemImage::create( path + normal, path + selected, callback );
    buttonImg->setPosition( position );
    
    auto buttonMenu = Menu::create( buttonImg, nullptr );
    buttonMenu->setPosition( Vec2::ZERO );
    addChild( buttonMenu );
}