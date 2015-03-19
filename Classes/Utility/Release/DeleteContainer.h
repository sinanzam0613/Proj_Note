#ifndef _DELETE_CONTAINER_H_
#define _DELETE_CONTAINER_H_

#include <list>
#include <map>

/**
 *	@class	：	DeleteContainer
 *	@brief	：	ポインタを使用した要素を持つコンテナの削除を行うクラス
 *	@author	：	利川聖太
 */
class DeleteContainer
{
	
public:
	
	/**
	 *	@brief	リストの全要素削除
	 *	@param	list	削除するリスト
	 */
	template< typename T >
	static void cleanList( std::list< T* >& list );
	
	/**
	 *	@brief	マップの全要素削除
	 *	@param	map	削除するマップ
	 */
	template< typename KEY, typename VALUE >
	static void cleanMap( std::map< KEY, VALUE* >& map );
};

// 実装ヘッダ
#include "DeleteContainerImpl.h"

#endif