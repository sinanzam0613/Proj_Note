#ifndef _GAME_TITLE_SCENE_H_
#define _GAME_TITLE_SCENE_H_

#include "cocos2d.h"
#include "GameTitleScreen.h"

/**
 *	@class	：	GameTitleScene
 *	@brief	：	ゲームタイトルシーンクラス
 *	@author	：	利川聖太
 */
class GameTitleScene : public cocos2d::LayerColor
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	GameTitleScene();
	
	/**
	 *	@brief	デストラクタ
	 */
	~GameTitleScene();
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	GameTitleScene	インスタンス
	 */
	static GameTitleScene* create();
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が完了したか否か
	 */
	virtual bool init() override;
	
	/**
	 *	@brief	更新
	 *	@param	deltaTime	デルタ時間
	 */
	virtual void update( float deltaTime ) override;
	
private:
	
	// メンバ変数の宣言
	GameTitleScreen*	mGameTitleScreen;
};

#endif