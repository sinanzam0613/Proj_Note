#ifndef GAMEDATAMEDIATOR_H
#define GAMEDATAMEDIATOR_H

#include "../../Object/Manager/PlayerManager.h"
#include "../../Object/StageObject/Block/BlockManager.h"

class UiObjectLayer;

class GameDataMediator : public cocos2d::Node
{
private:
	GameDataMediator() = default;
	~GameDataMediator() = default;
public:
	static GameDataMediator* create();

	virtual bool init();

	void update(float dt, UiObjectLayer* uilayer);

	PlayerManager* mPlayerManager;
	BlockManager* mBlockManager;
};

#endif
