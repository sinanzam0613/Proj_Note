#include "Block.h"
#include "../ObjectType.h"

using namespace cocos2d;

Block::Block()
{
	
}

Block::~Block()
{
	
}

Block* Block::create( const std::string& nodeName, const Vec2& pos )
{
	auto inst = new Block();
	
	if ( inst && inst->init( nodeName, pos ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool Block::init( const std::string& nodeName, const Vec2& pos )
{
	if ( !Sprite::initWithFile( "Texture/GamePlay/Character/BluePoint.png" ) )
	{
		return false;
	}
	
	this->setName( nodeName );
	this->enableCollision( nodeName );
	this->setPosition( pos );
	
	mPhysicsBody = PhysicsBody::createBox( cocos2d::Size( this->getContentSize().width, this->getContentSize().height ), mPhysicsMaterial );
	mPhysicsBody->setDynamic( false );
	mPhysicsBody->setCategoryBitmask( static_cast< int >( ObjectType::OBJECT_BLOCK_RED ) );
	mPhysicsBody->setContactTestBitmask( static_cast< int >( ObjectType::OBJECT_PLAYER_RED ) | static_cast< int >( ObjectType::OBJECT_BLOCK_RED ) );
	mPhysicsBody->setCollisionBitmask( 0xFFFFFFFF );
	this->setPhysicsBody( mPhysicsBody );
	
	return true;
}

void Block::onContactBegin( Node* contactNode )
{
	this->setTexture( "Texture/GamePlay/Character/BlueStand.png" );
	
	mPhysicsBody = PhysicsBody::createBox( cocos2d::Size( this->getContentSize().width, this->getContentSize().height ), mPhysicsMaterial );
	mPhysicsBody->setDynamic( false );
	mPhysicsBody->setCategoryBitmask( static_cast< int >( ObjectType::OBJECT_BLOCK_RED ) );
	mPhysicsBody->setContactTestBitmask( static_cast< int >( ObjectType::OBJECT_PLAYER_RED ) );
	mPhysicsBody->setCollisionBitmask( 0xFFFFFFFF );
	this->setPhysicsBody( mPhysicsBody );
}