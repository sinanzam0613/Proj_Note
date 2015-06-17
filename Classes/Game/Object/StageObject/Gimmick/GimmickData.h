#ifndef GIMMICKDATA_H
#define GIMMICKDATA_H

#include "string"
#include "../Gimmick/GimmickType.h"

struct GimmickData {
	std::string		textureName;
	int				positionX;
	int				positionY;
	int				objectType;

	GimmickData() {
		textureName = "";
		positionX   = 0;
		positionY   = 0;
		objectType  = 0;
	}

	GimmickData( const std::string& texName, int posX, int posY, int type) {
		textureName = texName;
		positionX = posX;
		positionY = posY;
		objectType = type;
	}
};

#endif