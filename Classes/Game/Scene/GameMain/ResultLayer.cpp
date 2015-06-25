#include "ResultLayer.h"
#include "../GameMain/GameMainScene.h"
#include "Game/Scene/Title/TitleScene.h"
#include "../../../Utility/SceneSupport/SceneCreator.h"


using namespace cocos2d;

ResultLayer::ResultLayer():
mIsAnimation(false)
{
    
}

ResultLayer::~ResultLayer()
{
    stopAllActions();
}

ResultLayer* ResultLayer::create(cocos2d::RenderTexture* sprite)
{
    auto inst = new ResultLayer();
    
    if ( inst && inst->init( sprite ) )
    {
        inst->autorelease();
        return inst;
    }
    
    CC_SAFE_DELETE( inst );
    return nullptr;
}

bool ResultLayer::init(cocos2d::RenderTexture* sprite)
{
    if ( !LayerColor::initWithColor( Color4B::BLACK ) )
    {
        return false;
    }
    
    sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    
    addChild(sprite, -1);
    
    if(!mIsAnimation){
        selectScene();
    }
    
    return true;
}

void ResultLayer::selectScene(){
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
    
    putButton( "Pause_Continue.png",	"Pause_Continue.png",	Vec2( 640, 410 ), continueCallback	);
    putButton( "Pause_ReStart.png",		"Pause_ReStart.png",	Vec2( 640, 270 ), nextCallback		);
    putButton( "Pause_End.png",			"Pause_End.png",		Vec2( 640, 134 ), titleCallback     );
    
    setOpacity( 120 );
    
    
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