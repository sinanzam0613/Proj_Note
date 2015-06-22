#ifndef _TESTOBJECT_H_
#define _TESTOBJECT_H_

#include "cocos2d.h"


/********************************************
プレイヤーの取り付くテストオブジェクト
後で消します
作成者　小林勇輝
*********************************************/
class TestObject:public cocos2d::Node
{
public:
	TestObject();
	~TestObject();
	virtual bool init()override;
	virtual void update(float deltaTime)override;
	CREATE_FUNC(TestObject);
	virtual void setPosition(const cocos2d::Vec2& pos)override;

	void dead();
private:
	cocos2d::Sprite* mSprite;
};

#endif