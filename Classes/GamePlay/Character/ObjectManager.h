#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_

//インクルード
#include "cocos2d.h"

//クラスの前方宣言
class Player;
class TestObject;

/*****************************************

ファイル名: ObjectManager.h
作成者: 小林勇輝

レイヤーのクラスが汚くならないように
仮の管理クラス作成しました

******************************************/
class ObjectManager:public cocos2d::Node
{
public:
	ObjectManager();
	~ObjectManager();
	virtual bool init()override;
	virtual void update(float deltaTime)override;
	static ObjectManager* create();

	void onTouchBegan(cocos2d::Vec2 touchPoint);
private:
	Player* mKatsumi;
	TestObject* mObject;
};


#endif