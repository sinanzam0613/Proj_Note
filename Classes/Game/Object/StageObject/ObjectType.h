#ifndef _OBJECT_TYPE_H_
#define _OBJECT_TYPE_H_

/**
 *	@class	：	ObjectType
 *	@brief	：	剛体に割り当てるマスク
 *	@author	：	利川聖太
 */
enum class ObjectType : int
{
	OBJECT_PLAYER_RED	= 1 << 0,
	OBJECT_PLAYER_BLUE	= 1 << 1,
	OBJECT_BLOCK_RED	= 1 << 2,
	OBJECT_BLOCK_BLUE	= 1 << 3,
};
	
#endif