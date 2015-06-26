#include "NormalBlock.h"
#include "../ObjectType.h"

#include "Utility/Audio/ADX2Player.h"

using namespace cocos2d;

NormalBlock::NormalBlock()
	: mBlockData( BlockData() )
{

}

NormalBlock::~NormalBlock()
{
	//this->disableCollision( this->getName() );
}

NormalBlock* NormalBlock::create( const std::string& nodeName, const BlockData& data )
{
	auto inst = new NormalBlock();
	
	if ( inst && inst->init( nodeName, data ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool NormalBlock::init( const std::string& nodeName, const BlockData& data )
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

void NormalBlock::onContactBegin( Node* contactNode )
{
	auto p = static_cast< ADX2Player* >(getParent()->getParent()->getChildByName("Player"));
	p->play(mBlockData.cueID);
}

void NormalBlock::initPhysics()
{
	auto size = cocos2d::Size( this->getContentSize().width, this->getContentSize().height );
	
	mPhysicsBody = PhysicsBody::createBox( size, mPhysicsMaterial );
	mPhysicsBody->setDynamic( false );
	mPhysicsBody->setCategoryBitmask( converter::toInt( ObjectType::OBJECT_BLOCK_NORMAL ) );
	mPhysicsBody->setContactTestBitmask( converter::toInt( ObjectType::OBJECT_ALL ) );
	mPhysicsBody->setCollisionBitmask( converter::toInt( ObjectType::OBJECT_ALL ) );
	this->setPhysicsBody( mPhysicsBody );
}