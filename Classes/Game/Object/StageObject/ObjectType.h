#ifndef _OBJECT_TYPE_H_
#define _OBJECT_TYPE_H_

enum class ObjectType : int
{
	OBJECT_BLOCK_RED	= 1 << 0,
	OBJECT_BLOCK_BLUE	= 1 << 1,
	OBJECT_PLAYER_RED	= 1 << 2,
	OBJECT_PLAYER_BLUE	= 1 << 3,
	OBJECT_ALL			= 1 << 4,
};

#endif