#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "cocos2d.h"
#include "Utility/Collision/Collider.h"
#include "BlockData.h"

class Block : public cocos2d::Sprite, public Collider
{
	
protected:
	
	Block();
	
	~Block();
	
public:
	
	static Block* create( const std::string& nodeName, const BlockData& data );
	
	bool init( const std::string& nodeName, const BlockData& data );
	
	virtual void onContactBegin( cocos2d::Node* contactNode ) override;
	
private:
	
	void initPhysics();
	
private:
	
	BlockData	mBlockData;
	bool		mIsTextureChanged;
};

#endif