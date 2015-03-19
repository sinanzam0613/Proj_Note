#ifndef _APP_DELEGATE_H_
#define _APP_DELEGATE_H_

#include "cocos2d.h"
#include "Utility/Audio/ADX2Manager.h"

/**
 *	@class	：	AppDelegate
 *	@brief	：	アプリケーション統括者クラス
 *	@author	：	利川聖太
 */
class AppDelegate : private cocos2d::Application
{
	
public:
	
	/**
	 *	@brief	コンストラクタ
	 */
	AppDelegate();
	
	/**
	 *	@brief	デストラクタ
	 */
	virtual ~AppDelegate();
	
	/**
	 *	@brief	アプリケーションの起動準備が整った時に呼ばれるコールバック関数
	 *	@return	bool	アプリケーションを開始するか否か
	 */
	virtual bool applicationDidFinishLaunching() override;
	
	/**
	 *	@brief	アプリケーションが非アクティブ状態になった時に呼ばれるコールバック関数
	 */
	virtual void applicationDidEnterBackground() override;
	
	/**
	 *	@brief	アプリケーションがアクティブ状態になった時に呼ばれるコールバック関数
	 */
	virtual void applicationWillEnterForeground() override;
	
private:
	
	// メンバ変数の宣言
	ADX2Manager*	mADX2Manager;
};

#endif