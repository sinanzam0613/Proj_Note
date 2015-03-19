#ifndef _RELEASE_CONTAINER_H_
#define _RELEASE_CONTAINER_H_

#include <list>
#include <map>

/**
 *	@class	：	ReleaseContainer
 *	@brief	：	Refクラスを継承した要素を持つコンテナの解放を行うクラス
 *	@author	：	利川聖太
 */
class ReleaseContainer
{
	
public:
	
	/**
	 *	@brief	リストの全要素解放
	 *	@param	list	解放するリスト
	 */
	template< typename T >
	static void cleanList( std::list< T* >& list );
	
	/**
	 *	@brief	マップの全要素解放
	 *	@param	map	解放するマップ
	 */
	template< typename KEY, typename VALUE >
	static void cleanMap( std::map< KEY, VALUE* >& map );
};

// 実装ヘッダ
#include "ReleaseContainerImpl.h"

#endif