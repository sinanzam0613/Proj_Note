#include "GameTitleScreen.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"
#include "Game/Object/StageObject/Block/BlockManager.h"
#include "Utility/SceneSupport/SceneCreator.h"
#include "HigeLayer.h"

using namespace cocos2d;

GameTitleScreen* GameTitleScreen::create()
{
	auto inst = new GameTitleScreen();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool GameTitleScreen::init()
{
	auto onTouchBegan	= CC_CALLBACK_2( GameTitleScreen::onTouchBegan, this );
	auto onTouchEnded	= CC_CALLBACK_2( GameTitleScreen::onTouchEnded, this );
	ListenerAssistant::setupSingleTouchListener( this, true, onTouchBegan, nullptr, onTouchEnded, nullptr );
	
	auto debugLabel = Label::createWithTTF( "GameClear!!", "Font/MarkerFelt.ttf", 64 );
	debugLabel->setColor( Color3B::RED );
	debugLabel->setAnchorPoint( Vec2::ANCHOR_TOP_LEFT );
	debugLabel->setPosition( Vec2( 200, 300 ) );
	this->addChild( debugLabel );
	
	//auto blockManager = BlockManager::create();
	//this->addChild( blockManager );
	
	return true;
}

bool GameTitleScreen::onTouchBegan( Touch* touch, Event* event )
{
	auto scene = SceneCreator::createPhysicsScene(HigeLayer::create(), Vect(0, -9.8f), 5.0f, true);
	Director::getInstance()->replaceScene(scene);
	return true;
}

void GameTitleScreen::onTouchEnded( Touch* touch, Event* event )
{
	
}