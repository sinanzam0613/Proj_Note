#ifndef _BLOCK_DATA_H_
#define _BLOCK_DATA_H_

#include "string"
#include "../ObjectType.h"

struct BlockData
{
	std::string		pointTextureName;
	std::string		blockTextureName;
	int				cueID;
	int				positionX;
	int				positionY;
	int				objectType;
	
	BlockData()
	{
		pointTextureName	= "";
		blockTextureName	= "";
		cueID				= 0;
		positionX			= 0;
		positionY			= 0;
		objectType			= 0;
	}
	
	BlockData( const std::string& point, const std::string& block, int cue, int posX, int posY, int type )
	{
		pointTextureName	= point;
		blockTextureName	= block;
		cueID				= cue;
		positionX			= posX;
		positionY			= posY;
		objectType			= type;
	}
};

#endif