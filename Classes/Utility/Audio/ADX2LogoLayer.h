#ifndef _ADX2_LOGOLAYER_H_
#define _ADX2_LOGOLAYER_H_

#include "cocos2d.h"

/**
 *	@class	：	ADX2LogoLayer
 *	@brief	：	ADX2のロゴ描画レイヤ( 必須ではない。 )
 *	@author	：	利川聖太
 */
class ADX2LogoLayer : public cocos2d::Layer
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ADX2LogoLayer() = default;
	
	/**
	 *	@brief	デストラクタ
	 */
	~ADX2LogoLayer() = default;
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	ADX2LogoLayer	インスタンス
	 */
	static ADX2LogoLayer* create();
	
	/**
	 *	@brief	初期化
	 *	@return	bool	初期化が成功したか否か
	 */
	virtual bool init() override;
};

#endif