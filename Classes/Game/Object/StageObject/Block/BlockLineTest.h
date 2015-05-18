#ifndef _BLOCKLIENTEST_H_
#define _BLOCKLIENTEST_H_

#include "cocos2d.h"
#include <vector>
#include <string>

class Block;

class BlockLineTest {
public:
private:
	typedef std::vector<Block*> BlockList;

	BlockList mBlockKist;
};

#endif