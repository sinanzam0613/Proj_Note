#ifndef _BLOCK_MANAGER_H_
#define _BLOCK_MANAGER_H_

#include "cocos2d.h"

class BlockManager : public cocos2d::Node
{
	
protected:
	
	BlockManager() = default;
	
	~BlockManager() = default;
	
public:
	
	static BlockManager* create();
	
	virtual bool init() override;
	
private:
	
	cocos2d::Node*	mBlockNode;
};

#endif