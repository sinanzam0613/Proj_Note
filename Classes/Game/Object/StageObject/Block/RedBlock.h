#ifndef _RED_BLOCK_H_
#define _RED_BLOCK_H_

#include "cocos2d.h"
#include "Utility/Collision/Collider.h"
#include "BlockData.h"

enum class ObjectType : int;

class RedBlock : public cocos2d::Sprite, public Collider
{
	
protected:
	
	RedBlock();
	
	~RedBlock();
	
public:
	
	static RedBlock* create( const std::string& nodeName, const BlockData& data );
	
	bool init( const std::string& nodeName, const BlockData& data );
	
	virtual void onContactBegin( cocos2d::Node* contactNode ) override;
	
	bool isChange() const;
	
private:
	
	void initPhysics();
	
private:
	
	BlockData	mBlockData;
	bool		mIsChanged;
};

#endif