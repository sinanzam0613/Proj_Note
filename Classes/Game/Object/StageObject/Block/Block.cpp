#include "Block.h"
<<<<<<< HEAD
#include "ObjectType.h"
=======
#include "../ObjectType.h"
>>>>>>> origin/master

using namespace cocos2d;

Block::Block()
{
	
}

Block::~Block()
{
<<<<<<< HEAD
	this->disableCollision( this->getName() );
}

Block* Block::create( const std::string& nodeName, int queID )
{
	auto inst = new Block();
	
	if ( inst && inst->init( nodeName, queID ) )
=======
	
}

Block* Block::create( const std::string& nodeName, const Vec2& pos )
{
	auto inst = new Block();
	
	if ( inst && inst->init( nodeName, pos ) )
>>>>>>> origin/master
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

<<<<<<< HEAD
bool Block::init( const std::string& nodeName, int queID )
{
	if ( !Sprite::initWithFile( "Texture/GamePlay/Character/Player.png" ) )
=======
bool Block::init( const std::string& nodeName, const Vec2& pos )
{
	if ( !Sprite::initWithFile( "Texture/GamePlay/Character/BluePoint.png" ) )
>>>>>>> origin/master
	{
		return false;
	}
	
	this->setName( nodeName );
<<<<<<< HEAD
	this->setScale( 0.3f, 0.2f );
	this->enableCollision( nodeName );
	
	mPhysicsBody = PhysicsBody::createBox( Size( this->getContentSize().width, this->getContentSize().height ), mPhysicsMaterial );
	//mPhysicsBody->setCategoryBitmask(true);//static_cast< int >( ObjectType::OBJECT_BLOCK ) );
	mPhysicsBody->setContactTestBitmask(true);//static_cast< int >( ObjectType::OBJECT_PLAYER ) );
	mPhysicsBody->setCollisionBitmask( true );
	mPhysicsBody->setDynamic(true);
	
=======
	this->enableCollision( nodeName );
	this->setPosition( pos );
	
	mPhysicsBody = PhysicsBody::createBox( cocos2d::Size( this->getContentSize().width, this->getContentSize().height ), mPhysicsMaterial );
	mPhysicsBody->setDynamic( false );
	mPhysicsBody->setCategoryBitmask( static_cast< int >( ObjectType::OBJECT_BLOCK_RED ) );
	mPhysicsBody->setContactTestBitmask( static_cast< int >( ObjectType::OBJECT_PLAYER_RED ) | static_cast< int >( ObjectType::OBJECT_BLOCK_RED ) );
	mPhysicsBody->setCollisionBitmask( 0xFFFFFFFF );
>>>>>>> origin/master
	this->setPhysicsBody( mPhysicsBody );
	
	return true;
}

void Block::onContactBegin( Node* contactNode )
{
<<<<<<< HEAD
	this->setScale( 1.0f, 1.0f );
	
	mPhysicsBody->release();
	mPhysicsBody = PhysicsBody::createBox( Size( this->getContentSize().width, this->getContentSize().height ), mPhysicsMaterial );
	mPhysicsBody->setCategoryBitmask( static_cast< int >( ObjectType::OBJECT_BLOCK ) );
	mPhysicsBody->setContactTestBitmask( static_cast< int >( ObjectType::OBJECT_PLAYER ) );
	mPhysicsBody->setCollisionBitmask( INT_MAX );
=======
	CCLOG( "ta" );
	this->setTexture( "Texture/GamePlay/Character/BlueStand.png" );
	
	mPhysicsBody = PhysicsBody::createBox( cocos2d::Size( this->getContentSize().width, this->getContentSize().height ), mPhysicsMaterial );
	mPhysicsBody->setDynamic( false );
	mPhysicsBody->setCategoryBitmask( static_cast< int >( ObjectType::OBJECT_BLOCK_RED ) );
	mPhysicsBody->setContactTestBitmask( static_cast< int >( ObjectType::OBJECT_PLAYER_RED ) );
	mPhysicsBody->setCollisionBitmask( 0xFFFFFFFF );
	this->setPhysicsBody( mPhysicsBody );
>>>>>>> origin/master
}