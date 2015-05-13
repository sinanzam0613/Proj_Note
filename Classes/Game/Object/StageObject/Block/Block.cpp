#include "Block.h"

using namespace cocos2d;

Block::Block()
	: mBlockData( BlockData() )
{
	
}

Block::~Block()
{
	this->disableCollision( this->getName() );
}

Block* Block::create( const std::string& nodeName, const BlockData& data )
{
	auto inst = new Block();
	
	if ( inst && inst->init( nodeName, data ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool Block::init( const std::string& nodeName, const BlockData& data )
{
	if ( !Sprite::initWithFile( data.pointTextureName ) )
	{
		return false;
	}
	
	mBlockData = data;
	
	this->setName( nodeName );
	this->enableCollision( nodeName );
	this->setPosition( Vec2( mBlockData.positionX, mBlockData.positionY ) );
	
	initPhysics();
	
	return true;
}

void Block::onContactBegin( Node* contactNode )
{
	this->setTexture( mBlockData.blockTextureName );
	
	initPhysics();
}

void Block::initPhysics()
{
	auto size = cocos2d::Size( this->getContentSize().width, this->getContentSize().height );
	
	mPhysicsBody = PhysicsBody::createBox( size, mPhysicsMaterial );
	mPhysicsBody->setDynamic( false );
	mPhysicsBody->setCategoryBitmask( mBlockData.objectType );
	mPhysicsBody->setContactTestBitmask( mBlockData.objectType );
	mPhysicsBody->setCollisionBitmask( 0xFFFFFFFF );
	this->setPhysicsBody( mPhysicsBody );
}