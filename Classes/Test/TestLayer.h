#ifndef _TESTLAYER_H_
#define _TESTLAYER_H_

//インクルード
#include "cocos2d.h"

//クラスの前方宣言
class ObjectManager;


/**************************************************

ファイル名 : TestLayer.h
作成者 : 小林勇輝

プレイヤー等の挙動確認のためのテストシーンです。

**************************************************/
class TestLayer : public cocos2d::Layer
{

protected:
	/********************************
	コンストラクタ
	*********************************/
	TestLayer();

	/********************************
	デストラクタ
	*********************************/
	~TestLayer();


public:
	/********************************
	初期化
	*********************************/
	virtual bool init() override;

	/*********************************
	更新
	**********************************/
	virtual void update(float deltaTime)override;

	/**********************************
	シーンの作成
	**********************************/
	static TestLayer* create();

	/*************************************
	タッチ始め
	***************************************/
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	/*************************************
	タッチ終わり
	***************************************/
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

private:
	ObjectManager* manager;
};

#endif