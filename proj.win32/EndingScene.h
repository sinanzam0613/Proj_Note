#ifndef EndingScene_H
#define EndingScene_H

#include "GameMainState.h"

class EndingScene : public cocos2d::Layer
{
public:
	EndingScene();
	~EndingScene();

	static EndingScene* create();

	bool init();

	GameMainState* mState;

	void update(float at);

	/*----------------------------------------------------------------------
	|	・タッチ始め
	----------------------------------------------------------------------*/
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	/*----------------------------------------------------------------------
	|	・タッチ終わり
	----------------------------------------------------------------------*/
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

};

#endif