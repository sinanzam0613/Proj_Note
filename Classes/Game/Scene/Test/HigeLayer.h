#ifndef _HIGE_LAYER_H_
#define _HIGE_LAYER_H_

#include "cocos2d.h"
#include <vector>

//クラス前方宣言
class ADX2Player;
class NoteManager;

/**
 *	@class	：	HigeLayer
 *	@brief	：	作業用レイヤー
 *	@author	：	石川貴康
 */
class HigeLayer : public cocos2d::LayerColor {
protected:

	/**
	 *	@brief	コンストラクタ
	 */
	HigeLayer();

	/**
	 *	@brief	デストラクタ
	 */
	~HigeLayer();
public:

	/**
	 *	@brief	初期化
	 *	@return	bool	初期化の成否
	 */
	virtual bool init() override;

	/**
	 *	@brief	更新
	 *	@pram	deltaTime	1fの更新にかかった時間
	 */
	virtual void update(float deltaTime)override;

	/**
	 *	@brief	タッチ開始時の判定
	 *	@pram	touch	タッチした座標
	 *	@pram	event	現在のイベント　タッチ数　
	 */
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	
	/**
	 *	@brief	タッチ中の判定
	 *	@pram	touch	タッチ中の座標
	 *	@pram	event	現在のイベント　タッチ数
	 */
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	
	/**
	 *	@brief	タッチ終了時のの判定
	 *	@pram	touch	指を離した時の座標
	 *	@pram	event	現在のイベント　タッチ数
	 */
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	HigeLayer	インスタンス
	 */
	static HigeLayer* create();


private:

	//メンバ変数宣言
	NoteManager* mNoteManager;

};

#endif