#include "GameTitleScreen.h"
#include "Utility/CocosAssistant/ListenerAssistant.h"
#include "Game/Object/StageObject/Block/BlockManager.h"

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
	
	auto debugLabel = Label::createWithTTF( "GameTitleScreen", "Font/MarkerFelt.ttf", 64 );
	debugLabel->setColor( Color3B::RED );
	debugLabel->setAnchorPoint( Vec2::ANCHOR_TOP_LEFT );
	debugLabel->setPosition( Vec2( 40, 1200 ) );
	this->addChild( debugLabel );
	
	auto blockManager = BlockManager::create();
	this->addChild( blockManager );
	
	return true;
}

bool GameTitleScreen::onTouchBegan( Touch* touch, Event* event )
{
	return true;
}

void GameTitleScreen::onTouchEnded( Touch* touch, Event* event )
{
	
}