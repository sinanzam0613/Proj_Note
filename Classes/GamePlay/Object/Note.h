#ifndef _NOTE_H_
#define _NOTE_H_

#include "cocos2d.h"

/**
 *	@class	：	Note
 *	@brief	：	音符
 *	@author	：	石川貴康
 */
class Note :public cocos2d::Node {
protected:

	/**
	 *	@brief	コンストラクタ
	 */
	Note();

	/**
	 *	@brief	デストラクタ
	 */
	~Note();
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
	virtual void update(float deltaTime) override;

	/**
	 *	@brief	インスタンスの生成
	 *	@return	Note	インスタンス
	 */
	static Note* createObject();

private:

	//メンバ関数の宣言
	cocos2d::Sprite* mSprite;
};

#endif