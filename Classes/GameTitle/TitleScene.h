#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "TitleState.h"

class TitleScene : public cocos2d::Layer
{
public:
	TitleScene();
	~TitleScene();

	static TitleScene* create();

	bool init();

	TitleState* mState;

	void update(float at);

	/*----------------------------------------------------------------------
	|	�E�^�b�`�n��
	----------------------------------------------------------------------*/
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	/*----------------------------------------------------------------------
	|	�E�^�b�`�I���
	----------------------------------------------------------------------*/
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

};

#endif