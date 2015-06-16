#ifndef _BLUE_BLOCK_H_
#define _BLUE_BLOCK_H_

#include "cocos2d.h"
#include "Utility/Collision/Collider.h"
#include "BlockData.h"

enum class ObjectType : int;

class BlueBlock : public cocos2d::Sprite, public Collider
{
	
protected:
	
	BlueBlock();
	
	~BlueBlock();
	
public:
	
	static BlueBlock* create( const std::string& nodeName, const BlockData& data );
	
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