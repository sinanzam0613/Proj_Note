#include "GameDataMediator.h"
#include "Game/Object/UIObject/UiObjectLayer.h"
#include "Game/Object/Character/Player/Player.h"
#include "Utility/Action/Follow/CustomFollow.h"
#include "Game/Object/Character/Player/GoalAnimation.h"



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
	mGImmickManager = GimmickManager::create();
    
    timer.reset();
    timer.begin();

	mPlayerManager->add(cocos2d::Vec2(80, 210), cocos2d::Vec2(150, 210), 2, 2);

	this->addChild(mPlayerManager);
	this->addChild(mBlockManager);
	this->addChild(mGImmickManager);

	return true;
}

void GameDataMediator::update(float dt, UiObjectLayer* uiLayer){

	mPlayerManager->update(dt);
    
    auto userDef = cocos2d::UserDefault::getInstance();
    bool isClear = userDef->getBoolForKey("isClear");
    
    if(isClear){
        GoalAnimation goal;
        goal.action(mBlockManager->getGoalPos(),
                    this,
                    mPlayerManager->getPlayer(0)->getChildByName("Player"),
                    mPlayerManager->getPlayer(1)->getChildByName("Player2"));
        
        
        
        auto node = Node::create();
        auto func = cocos2d::CallFunc::create([&]() {
            mResult = ResultLayer::create(mBlockManager->getGoalPos());
            addChild(mResult,100);
        });
        auto delay = cocos2d::DelayTime::create(10.0f);
        auto seq = cocos2d::Sequence::create(delay, func, nullptr);
        node->runAction(seq);
        this->addChild(node);
        
    }

	SlideBar* slideBar = uiLayer->getSlideBar();

    Player* player = mPlayerManager->getPlayer(PLAYER1);
    
    if (slideBar->isTouch("p1", uiLayer)){
        player->changeJumpTime(slideBar->getValue("p1", uiLayer));
    }
    
    if (!player->getState() == JUMP)
    {
        player->jump(mBlockManager->getBlockPos(player->jumpCount()));
    }
    
    if (timer.getTime() <= 30)
    {
        timer.update();
        return;
    }
    
    Player* player2 = mPlayerManager->getPlayer(PLAYER2);
    
    if (slideBar->isTouch("p2", uiLayer)){
        player2->changeJumpTime(slideBar->getValue("p2", uiLayer));
    }
    
    if (!player2->getState() == JUMP){
        
        player2->jump(mBlockManager->getBlockPos(player2->jumpCount()));
    }
    


}

void GameDataMediator::setFollow(cocos2d::Layer* layer){
	auto follow = CustomAction::CustomFollow::create(mPlayerManager->getPlayer(PLAYER1), mPlayerManager->getPlayer(PLAYER2), CustomAction::CustomFollowXOnly, cocos2d::Rect(0, 0, 20000, 800));
	follow->setTag(1003);
	layer->runAction(follow);
}