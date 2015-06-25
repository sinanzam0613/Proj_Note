#ifndef STARTANIMATION_H
#define STARTANIMATION_H

#include "cocos2d.h"

class StartAnimation : public cocos2d::Node
{
protected:
	StartAnimation() = default;
	~StartAnimation() = default;
public:

	static StartAnimation* create();

	//スタート処理作成
	void set();

	/*
		スタートアニメーション用のSpriteを作成
	*/
	cocos2d::Sprite* createStartAnim(cocos2d::Size winSize,cocos2d::Sequence* action);

	/*
		スタートアニメーション用のアクションを作成
	*/
	cocos2d::Sequence* createSequence();
};

#endif
