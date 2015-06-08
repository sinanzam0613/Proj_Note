#ifndef OBJECTMANAGER_H_
#define OBJECTMANAGER_H_

//インクルード
#include "cocos2d.h"

//クラスの前方宣言
class Player;
class TestObject;
class PlayerManager;
class RestEnemy;
class EnemyManager;

/*****************************************

ファイル名: ObjectManager.h
作成者: 小林勇輝

レイヤーのクラスが汚くならないように
仮の管理クラス作成しました

******************************************/
class ObjectManager:public cocos2d::Node
{
public:
	/********************************************
	コンストラクタ
	********************************************/
	ObjectManager();
	/********************************************
	デストラクタ
	*********************************************/
	~ObjectManager();
	/********************************************
	初期化
	return: 初期化成功か否か
	*******************************************/
	virtual bool init()override;
	/********************************************
	更新
	deltaTime: デルタタイム
	********************************************/
	virtual void update(float deltaTime)override;

	/**********************************************
	生成関数
	***********************************************/
	static ObjectManager* create();

	

	void onTouchBegan(cocos2d::Vec2 touchPoint);


private:
	/*********************************************
	オブジェクトの距離チェック
	*********************************************/
	bool distanceCheck();
private:
	Player* mKatsumi;
	TestObject* mObject;
	PlayerManager* mPlayerManager;
	RestEnemy* mEnemy;
	EnemyManager* mEnemyManager;
};


#endif