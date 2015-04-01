#ifndef _GAME_TITLE_SCREEN_H_
#define _GAME_TITLE_SCREEN_H_

#include "cocos2d.h"

/**
 *	@class	：	GameTitleScreen
 *	@brief	：	ゲームタイトルシーンの実装を行うクラス
 *	@author	：	利川聖太
 */
class GameTitleScreen : public cocos2d::Node
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	GameTitleScreen() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~GameTitleScreen() = default;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	GameTitleScreen	インスタンス
	 */
	static GameTitleScreen* create();
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
	/**
	 *	@brief	タッチ開始時のコールバック関数
	 *	@param	touch	タッチ情報
	 *	@param	event	イベント情報
	 *	@return	bool	タッチを行ったか否か
	 */
	bool onTouchBegan( cocos2d::Touch* touch, cocos2d::Event* event );
	
	/**
	 *	@brief	タッチ終了時のコールバック関数
	 *	@param	touch	タッチ情報
	 *	@param	event	イベント情報
	 */
	void onTouchEnded( cocos2d::Touch* touch, cocos2d::Event* event );
};

#endif