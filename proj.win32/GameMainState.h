﻿#include "SceneSupport/IScene.h"

class GameMainState : public IScene
{
public:

	/*-------------------------------------------------------------------
	|	・コンストラクタ
	-------------------------------------------------------------------*/
	GameMainState() = default;


	/*-------------------------------------------------------------------
	|	・デストラクタ
	-------------------------------------------------------------------*/
	~GameMainState() = default;

	/*-------------------------------------------------------------------
	|	・レイヤーの生成
	-------------------------------------------------------------------*/
	static GameMainState* create(cocos2d::Layer* layer);

	/*-------------------------------------------------------------------
	|	・初期化
	--------------------------------------------------------------------*/
	bool init(cocos2d::Layer* layer) override;

	/*--------------------------------------------------------------------
	|	・更新
	|　 float at	１フレームにかかる時間
	--------------------------------------------------------------------*/
	void update(float at) override;

	/*--------------------------------------------------------------------
	|	・シーン始め
	-------------------------------------------------------------------*/
	void fadeIn(float at) override;


	/*------------------------------------------------------------------
	|	・ゲームメイン更新
	-------------------------------------------------------------------*/
	void sceneMain(float at) override;

	/*------------------------------------------------------------------
	|	・シーン終了
	------------------------------------------------------------------*/
	void fadeOut(float at)   override;


	/*----------------------------------------------------------------------
	|	・タッチ始め
	----------------------------------------------------------------------*/
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	/*----------------------------------------------------------------------
	|	・タッチ終わり
	----------------------------------------------------------------------*/
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);


private:
	/*------------------------------------------------------------------
	|	メインループ始め
	-------------------------------------------------------------------*/
	void mainStart(float at) override;


	/*------------------------------------------------------------------
	|	ゲームメイン更新
	-------------------------------------------------------------------*/
	void mainLoop(float at)  override;


	/*------------------------------------------------------------------
	|	メインループ終了
	------------------------------------------------------------------*/
	void mainEnd(float at)   override;

private:
	bool mTestTouch;
};

