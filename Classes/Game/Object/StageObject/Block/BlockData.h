#ifndef _BLOCK_DATA_H_
#define _BLOCK_DATA_H_

#include "string"

struct BlockData
{
	std::string		blockTextureName;
	int				cueID;
	int				positionX;
	int				positionY;
	
	BlockData()
	{
		blockTextureName	= "";
		cueID				= 0;
		positionX			= 0;
		positionY			= 0;
	}
	
	BlockData( const std::string& block, int cue, int posX, int posY )
	{
		blockTextureName	= block;
		cueID				= cue;
		positionX			= posX;
		positionY			= posY;
	}
};

#endif