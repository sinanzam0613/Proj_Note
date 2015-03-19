#ifndef _ADX2_MANAGER_H_
#define _ADX2_MANAGER_H_

#include "cocos2d.h"
#include "cri_adx2le.h"

#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
#include <AudioToolbox/AudioSession.h>
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#include "platform/android/jni/JniHelper.h"
#endif

/**
 *	@class	：	ADX2Manager
 *	@brief	：	ADX2全体の管理者クラス
 *	@author	：	利川聖太
 */
class ADX2Manager : public cocos2d::Ref
{
	
protected:
	
	/**
	 *	@brief	コンストラクタ
	 */
	ADX2Manager();
	
	/**
	 *	@brief	デストラクタ
	 */
	~ADX2Manager();
	
public:
	
	/**
	 *	@brief	インスタンスの生成
	 *	@return	ADX2Manager	インスタンス
	 */
	static ADX2Manager* create();
	
	/**
	 *	@brief	更新
	 *			ADX2のサーバ更新処理があるので
	 *			稼働中のシーンで必ず呼び出す必要があります。
	 */
	static void update();
	
	/**
	 *	@brief	初期化
	 *	@param	acf	ACFファイルのファイルパス
	 */
	void init( const std::string& acf );
	
	/**
	 *	@brief	アプリ中断時のコールバック関数
	 */
	void pauseApp();
	
	/**
	 *	@brief	アプリ再開時のコールバック関数
	 */
	void resumeApp();
	
private:
	
	/**
	 *	@brief	プラットフォーム別の初期化
	 */
	void initPlatformSetting();
	
private:
	
	// メンバ変数の宣言
	CriAtomDbasId	mDbasID;
};

#endif