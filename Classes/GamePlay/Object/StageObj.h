#ifndef STAGEOBJ_H
#define STAGEOBJ_H

#include "cocos2d.h"
#include "GamePlay/Character/SpriteCreator.h"

class StageObj : public cocos2d::Node{
public:

	virtual ~StageObj() = default;

	virtual void update(float deltatime) = 0;

	cocos2d::Sprite* mSprite;
};

#endif