#include "ADX2LogoLayer.h"
#include "../SceneSupport/SceneCreator.h"
#include "Game/Scene/Title/TitleScene.h"

using namespace cocos2d;

ADX2LogoLayer* ADX2LogoLayer::create()
{
	auto inst = new ADX2LogoLayer();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool ADX2LogoLayer::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	
	auto winSize	= Director::getInstance()->getWinSize();
	auto centerPos	= Vec2( winSize.width / 2, winSize.height / 2 );
	
	auto logo = Sprite::create( "ADX2/Logo_512.png" );
	logo->setPosition( centerPos );
	this->addChild( logo );
	
	auto changeSceneFunc = []()
	{
		auto nextScene	= SceneCreator::createScene( TitleScene::create() );
		auto scene		= TransitionFade::create( 1.5f, nextScene, Color3B::BLACK );
		Director::getInstance()->replaceScene( scene );
	};
	
	auto seqAct = Sequence::create( DelayTime::create( 3.0f ), CallFunc::create( changeSceneFunc ), nullptr );
	this->runAction( seqAct );
	
	return true;
}