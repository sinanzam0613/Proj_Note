#ifndef _OBJECT_TYPE_H_
#define _OBJECT_TYPE_H_

enum class ObjectType : int
{
	OBJECT_BLOCK_RED	= 1 << 0,
	OBJECT_BLOCK_BLUE	= 1 << 1,
	OBJECT_PLAYER_RED	= 1 << 2,
	OBJECT_PLAYER_BLUE	= 1 << 3,
	OBJECT_BLOCK_NORMAL	= 1 << 4,
	OBJECT_BLOCK_GOAL	= 1 << 5,
	OBJECT_ALL			= INT_MAX,	// 0xFFFFFFFFの代用品
	};
	
namespace converter
{
	int toInt( ObjectType type )
	{
		return static_cast< int >( type );
	}
	
	ObjectType toObjectType( int bit )
	{
		return static_cast< ObjectType >( bit );
	}
};
	
#endif