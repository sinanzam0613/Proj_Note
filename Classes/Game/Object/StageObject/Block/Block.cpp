#include "Block.h"
#include "ObjectType.h"

using namespace cocos2d;

Block::Block()
{
	
}

Block::~Block()
{
	this->disableCollision( this->getName() );
}

Block* Block::create( const std::string& nodeName, int queID )
{
	auto inst = new Block();
	
	if ( inst && inst->init( nodeName, queID ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool Block::init( const std::string& nodeName, int queID )
{
	if ( !Sprite::initWithFile( "Texture/GamePlay/Character/Player.png" ) )
	{
		return false;
	}
	
	this->setName( nodeName );
	this->setScale( 0.3f, 0.2f );
	this->enableCollision( nodeName );
	
	mPhysicsBody = PhysicsBody::createBox( Size( this->getContentSize().width, this->getContentSize().height ), mPhysicsMaterial );
	//mPhysicsBody->setCategoryBitmask(true);//static_cast< int >( ObjectType::OBJECT_BLOCK ) );
	mPhysicsBody->setContactTestBitmask(true);//static_cast< int >( ObjectType::OBJECT_PLAYER ) );
	mPhysicsBody->setCollisionBitmask( true );
	mPhysicsBody->setDynamic(true);
	
	this->setPhysicsBody( mPhysicsBody );
	
	return true;
}

void Block::onContactBegin( Node* contactNode )
{
	this->setScale( 1.0f, 1.0f );
	
	mPhysicsBody->release();
	mPhysicsBody = PhysicsBody::createBox( Size( this->getContentSize().width, this->getContentSize().height ), mPhysicsMaterial );
	mPhysicsBody->setCategoryBitmask( static_cast< int >( ObjectType::OBJECT_BLOCK ) );
	mPhysicsBody->setContactTestBitmask( static_cast< int >( ObjectType::OBJECT_PLAYER ) );
	mPhysicsBody->setCollisionBitmask( INT_MAX );
}