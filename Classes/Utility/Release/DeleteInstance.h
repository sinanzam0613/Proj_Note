#ifndef _DELETE_INSTANCE_H_
#define _DELETE_INSTANCE_H_

#include "cocos2d.h"

/**
 *	@class	：	DeleteInstance
 *	@brief	：	インスタンスを削除するクラス
 *	@author	：	利川聖太
 */
class DeleteInstance
{
	
public:
	
	/**
	 *	@brief	インスタンスを削除するか否かの関数オブジェクト
	 *	@param	instance	削除するインスタンス
	 *	@return	bool		インスタンスを削除するか否か
	 */
	template< typename T >
	bool operator () ( T* instance )
	{
		CC_SAFE_DELETE( instance );
		return true;
	}
};

#endif