#ifndef _GIMMICK_DATA_H_
#define _GIMMICK_DATA_H_

#include "string"

struct GimmickData
{
	std::string		gimmickTextureName;
	int				positionX;
	int				positionY;

	GimmickData()
	{
		gimmickTextureName = "";
		positionX = 0;
		positionY = 0;
	}

	GimmickData(const std::string& gimmick, int posX, int posY)
	{
		gimmickTextureName = gimmick;
		positionX = posX;
		positionY = posY;
	}
};

#endif