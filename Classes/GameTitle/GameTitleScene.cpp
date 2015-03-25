#include "GameTitleScene.h"
#include "GameTitleScreen.h"

using namespace cocos2d;

GameTitleScene::GameTitleScene()
	: mGameTitleScreen( GameTitleScreen::create() )
{
	
}

GameTitleScene::~GameTitleScene()
{
	
}

GameTitleScene* GameTitleScene::create()
{
	auto inst = new GameTitleScene();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool GameTitleScene::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	this->addChild( mGameTitleScreen );
	
	this->scheduleUpdate();
	
	return true;
}

void GameTitleScene::update( float deltaTime )
{
	mGameTitleScreen->update( deltaTime );
}