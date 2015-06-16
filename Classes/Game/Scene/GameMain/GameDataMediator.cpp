#include "GameDataMediator.h"
#include "Game/Object/UIObject/UiObjectLayer.h"


GameDataMediator* GameDataMediator::create(){
	auto ins = new GameDataMediator();

	if (ins && ins->init()){
		ins->autorelease();
		return ins;
	}
	CC_SAFE_DELETE(ins);
	return nullptr;
}

bool GameDataMediator::init(){
	if (!Node::init())
	{
		return false;
	}

	mPlayerManager = PlayerManager::create();
	mBlockManager = BlockManager::create();

	this->addChild(mPlayerManager);
	this->addChild(mBlockManager);
}

void GameDataMediator::update(float dt, UiObjectLayer* uilayer){

}