#ifndef GAMEDATAMEDIATOR_H
#define GAMEDATAMEDIATOR_H

#include "../../Object/Manager/PlayerManager.h"
#include "../../Object/StageObject/Block/BlockManager.h"
#include "../../Object/StageObject/Gimmick/GimmickManager.h"
#include "Game/Scene/GameMain/ResultLayer.h"
#include "Utility/Timer/Timer.h"

enum PLAYERS{
	PLAYER1 = 0,
	PLAYER2
};

class UiObjectLayer;

class GameDataMediator : public cocos2d::Node
{
private:
	GameDataMediator() = default;
	~GameDataMediator() = default;
public:
	static GameDataMediator* create();

	virtual bool init();

	void setFollow(cocos2d::Layer* layer);

	void update(float dt, UiObjectLayer* uilayer);

	void playerUpdate(float dt, UiObjectLayer* uilayer);

	PlayerManager* mPlayerManager;
	BlockManager* mBlockManager;
	GimmickManager* mGImmickManager;
    ResultLayer* mResult;
    int mCount;
    
private:
    MyUtil::Timer timer;
};

#endif
