#include "PauseLayer.h"
#include "../GameMain/GameMainScene.h"
#include "../Title/TitleScene.h"
#include "../../../Utility/SceneSupport/SceneCreator.h"

using namespace cocos2d;

PauseLayer::PauseLayer()
{
	
}

PauseLayer::~PauseLayer()
{
	stopAllActions();
}

PauseLayer* PauseLayer::create(cocos2d::RenderTexture* sprite)
{
	auto inst = new PauseLayer();
	
	if ( inst && inst->init( sprite ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool PauseLayer::init(cocos2d::RenderTexture* sprite)
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	addChild(sprite, -1);

	auto continueCallback = [&](Ref*) { Director::getInstance()->popScene(); };
	
	auto retryCallback		= [ & ]( Ref* )
	{
		Director::getInstance()->popScene();

		auto scene = SceneCreator::createPhysicsScene(GameMainScene::create(), Vect(0, -9.8f), 5.0f);
		auto fade	= TransitionFade::create( 1.5f, scene, Color3B::BLACK );
		Director::getInstance()->replaceScene( fade );
	};
	auto retireCallback		= [ & ]( Ref* )
	{
		Director::getInstance()->popScene();

		auto scene = SceneCreator::createPhysicsScene(TitleScene::create(), Vect(0, -9.8f), 5.0f);
		auto fade	= TransitionFade::create( 1.5f, scene, Color3B::BLACK );
		Director::getInstance()->replaceScene( fade );
	};
	
	auto icon = Sprite::create( "Texture/GamePlay/GameScene/Pause/Pause_Logo.png" );
	icon->setPosition( Vec2( 1190, 696 ) );
	
	putButton( "Pause_Continue.png",	"Pause_Continue.png",	Vec2( 640, 410 ), continueCallback	);
	putButton( "Pause_ReStart.png",		"Pause_ReStart.png",	Vec2( 640, 270 ), retryCallback		);
	putButton( "Pause_End.png",			"Pause_End.png",		Vec2( 640, 134 ), retireCallback	);
	
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