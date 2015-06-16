#ifndef _BLOCK_FACTORY_H_
#define _BLOCK_FACTORY_H_

#include "cocos2d.h"

class BlockFactory
{
	
public:
	
	void createBlock( cocos2d::Node* parentNode, const std::string& fileName );
};

#endif