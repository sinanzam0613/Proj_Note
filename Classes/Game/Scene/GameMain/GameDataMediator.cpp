#include "GameDataMediator.h"
#include "Game/Object/UIObject/UiObjectLayer.h"
#include "Game/Object/Character/Player/Player.h"
#include "Utility/Action/Follow/CustomFollow.h"


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


	mPlayerManager->add(cocos2d::Vec2(100, 230), cocos2d::Vec2(100, 230), 2, 2);

	this->addChild(mPlayerManager);
	this->addChild(mBlockManager);

	return true;
}

void GameDataMediator::update(float dt, UiObjectLayer* uiLayer){

	mPlayerManager->update(dt);

	SlideBar* slideBar = uiLayer->getSlideBar();

	Player* player2 = mPlayerManager->getPlayer(PLAYER2);

	if (slideBar->isTouch("p2", uiLayer)){
		player2->changeJumpTime(slideBar->getValue("p2", uiLayer));
	}

	if (!player2->getState() == JUMP){

		player2->jump(mBlockManager->getBlockPos(player2->jumpCount()));
	}

	Player* player = mPlayerManager->getPlayer(PLAYER1);

	if (slideBar->isTouch("p1", uiLayer)){
		player->changeJumpTime(slideBar->getValue("p1", uiLayer));
	}

	if (player->getState() == JUMP) return;

	player->jump(mBlockManager->getBlockPos(player->jumpCount()));

}

void GameDataMediator::setFollow(cocos2d::Layer* layer){
	auto follow = CustomAction::CustomFollow::create(mPlayerManager->getPlayer(PLAYER1), mPlayerManager->getPlayer(PLAYER2), CustomAction::CustomFollowXOnly, cocos2d::Rect(0, 0, 20000, 800));
	follow->setTag(1003);
	layer->runAction(follow);
}