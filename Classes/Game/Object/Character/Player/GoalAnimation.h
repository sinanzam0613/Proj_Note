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

	void action(Player* playerRed,Player* playerBlue);

private:
	MyUtil::Timer mTimer;
};


#endif