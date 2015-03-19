#ifndef _RELEASE_INSTANCE_H_
#define _RELEASE_INSTANCE_H_

#include "cocos2d.h"

/**
 *	@class	：	ReleaseInstance
 *	@brief	：	Refクラスを継承したインスタンスを解放するクラス
 *	@author	：	利川聖太
 */
class ReleaseInstance
{
	
public:
	
	/**
	 *	@brief	インスタンスを解放するか否かの関数オブジェクト
	 *	@param	instance	解放するインスタンス
	 *	@return	bool		インスタンスを解放するか否か
	 */
	bool operator () ( cocos2d::Ref* instance )
	{
		CC_SAFE_RELEASE_NULL( instance );
		return true;
	}
};

#endif