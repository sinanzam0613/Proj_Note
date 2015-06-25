#ifndef _GOALANIMATION_H_
#define _GOALANIMATION_H_

#include "cocos2d.h"
#include "Utility/Timer/Timer.h"

class Player;

class GoalAnimation
{
public:
	GoalAnimation();
	~GoalAnimation();

	void action(const cocos2d::Vec2& goalPosition ,cocos2d::Node* parentNode,cocos2d::Node* playerRed,cocos2d::Node* playerBlue);


private:
	void bellAnimation(const cocos2d::Vec2& goalPosition, cocos2d::Node* parentNode);
	void jumpAnimation(cocos2d::Node* playerRed, cocos2d::Node* playerBlue);
	void createEffect(cocos2d::Node* parent,cocos2d::Vec2 position);

private:
	MyUtil::Timer mTimer;
	int mJumpCount;
};

#endif