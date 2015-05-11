#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "cocos2d.h"
#include "Utility/Collision/Collider.h"

class Block : public cocos2d::Sprite, public Collider
{
	
public:
	
	Block();
	
	~Block();
	
	static Block* create( const std::string& nodeName, int queID );
	
	bool init( const std::string& nodeName, int queID );
	
	virtual void onContactBegin( cocos2d::Node* contactNode ) override;
};

#endif