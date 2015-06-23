#include "PauseLayer.h"
#include "../GameMain/GameMainScene.h"
#include "../../../Utility/SceneSupport/SceneCreator.h"

using namespace cocos2d;

PauseLayer::PauseLayer()
{
	
}

PauseLayer::~PauseLayer()
{
	stopAllActions();
}

PauseLayer* PauseLayer::create( const Vec2& position )
{
	auto inst = new PauseLayer();
	
	if ( inst && inst->init( position ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool PauseLayer::init( const Vec2& position )
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	auto continueCallback	= [ & ]( Ref* ) { this->removeFromParent(); };
	auto retryCallback		= [ & ]( Ref* )
	{
		auto scene	= SceneCreator::createScene( GameMainScene::create() );
		auto fade	= TransitionFade::create( 1.5f, scene, Color3B::BLACK );
		Director::getInstance()->replaceScene( fade );
	};
	auto retireCallback		= [ & ]( Ref* )
	{
		auto scene	= SceneCreator::createScene( GameMainScene::create() );
		auto fade	= TransitionFade::create( 1.5f, scene, Color3B::BLACK );
		Director::getInstance()->replaceScene( fade );
	};
	
	auto icon = Sprite::create( "Texture/GamePlay/GameScene/Pause/Pause_Logo.png" );
	icon->setPosition( Vec2( 1190, 696 ) );
	
	putButton( "Pause_Continue.png",	"Pause_Continue.png",	Vec2( 640, 410 ), continueCallback	);
	putButton( "Pause_ReStart.png",		"Pause_ReStart.png",	Vec2( 640, 270 ), retryCallback		);
	putButton( "Pause_End.png",			"Pause_End.png",		Vec2( 640, 134 ), retireCallback	);
	
	setPosition( position );
	setOpacity( 120 );
	
	return true;
}

void PauseLayer::putButton( const std::string& normal, const std::string& selected, const Vec2& position, ButtonCallback callback )
{
	const auto path = "Texture/GamePlay/GameScene/Pause/";
	
	auto buttonImg = MenuItemImage::create( path + normal, path + selected, callback );
	buttonImg->setPosition( position );
	
	auto buttonMenu = Menu::create( buttonImg, nullptr );
	buttonMenu->setPosition( Vec2::ZERO );
	addChild( buttonMenu );
}