#ifndef _OBJECT_TYPE_H_
#define _OBJECT_TYPE_H_

enum class ObjectType : int
{
	OBJECT_PLAYER	= 1 << 0,
	OBJECT_BLOCK	= 1 << 1,
};

#endif