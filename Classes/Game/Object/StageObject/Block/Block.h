#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "cocos2d.h"
#include "Utility/Collision/Collider.h"

class Block : public cocos2d::Sprite, public Collider
{
	
<<<<<<< HEAD
public:
=======
protected:
>>>>>>> origin/master
	
	Block();
	
	~Block();
	
<<<<<<< HEAD
	static Block* create( const std::string& nodeName, int queID );
	
	bool init( const std::string& nodeName, int queID );
	
	virtual void onContactBegin( cocos2d::Node* contactNode ) override;
=======
public:
	
	static Block* create( const std::string& nodeName, const cocos2d::Vec2& pos );
	
	bool init( const std::string& nodeName, const cocos2d::Vec2& pos );
	
	virtual void onContactBegin( cocos2d::Node* contactNode );
>>>>>>> origin/master
};

#endif