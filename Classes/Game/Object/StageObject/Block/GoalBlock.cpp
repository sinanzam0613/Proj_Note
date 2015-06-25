#include "GoalBlock.h"
#include "../ObjectType.h"

using namespace cocos2d;

GoalBlock::GoalBlock()
	: mBlockData( BlockData() )
{
	
}

GoalBlock::~GoalBlock()
{
	this->disableCollision( this->getName() );
}

GoalBlock* GoalBlock::create( const std::string& nodeName, const BlockData& data )
{
	auto inst = new GoalBlock();
	
	if ( inst && inst->init( nodeName, data ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool GoalBlock::init( const std::string& nodeName, const BlockData& data )
{
	if ( !Sprite::initWithFile( data.blockTextureName + ".png" ) )
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

void GoalBlock::onContactBegin( Node* contactNode )
{
    UserDefault* useDef  = UserDefault::getInstance();
    useDef->setBoolForKey("isClear", true);
    useDef->flush();
}

void GoalBlock::initPhysics()
{
	auto size = cocos2d::Size( this->getContentSize().width, this->getContentSize().height );
	
	mPhysicsBody = PhysicsBody::createBox( size, mPhysicsMaterial );
	mPhysicsBody->setDynamic( false );
	mPhysicsBody->setCategoryBitmask( converter::toInt( ObjectType::OBJECT_BLOCK_GOAL ) );
	mPhysicsBody->setContactTestBitmask( converter::toInt( ObjectType::OBJECT_ALL ) );
	mPhysicsBody->setCollisionBitmask( converter::toInt( ObjectType::OBJECT_ALL ) );
	this->setPhysicsBody( mPhysicsBody );
}