#ifndef _GIMMICK_FACTORY_H_
#define _GIMMICK_FACTORY_H_

#include "cocos2d.h"

class GimmickFactory
{

public:

	void createGimmick(cocos2d::Node* parentNode, const std::string& fileName);
};

#endif