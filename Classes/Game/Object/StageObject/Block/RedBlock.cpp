#include "RedBlock.h"
#include "../ObjectType.h"

#include "Utility/Audio/ADX2Player.h"

using namespace cocos2d;

RedBlock::RedBlock()
	: mBlockData( BlockData() )
	, mIsChanged( false )
{
	
}

RedBlock::~RedBlock()
{
	//this->disableCollision( this->getName() );
}

RedBlock* RedBlock::create( const std::string& nodeName, const BlockData& data )
{
	auto inst = new RedBlock();
	
	if ( inst && inst->init( nodeName, data ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool RedBlock::init( const std::string& nodeName, const BlockData& data )
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

void RedBlock::onContactBegin( Node* contactNode )
{
	if ( mIsChanged ) return;
	
	int contactBit = contactNode->getPhysicsBody()->getCategoryBitmask();
	
	if ( converter::toObjectType( contactBit ) == ObjectType::OBJECT_PLAYER_RED )
	{
		auto p = static_cast< ADX2Player* >(getParent()->getParent()->getChildByName("Player"));
		p->play(mBlockData.cueID);
		auto name = mBlockData.blockTextureName + "After";
		setTexture( name + ".png" );
		setName( name );
		mIsChanged = true;
		initPhysics();
	}
}

void RedBlock::initPhysics()
{
	auto size = cocos2d::Size( this->getContentSize().width, this->getContentSize().height );
	
	mPhysicsBody = PhysicsBody::createBox( size, mPhysicsMaterial );
	mPhysicsBody->setDynamic( false );
	mPhysicsBody->setCategoryBitmask( converter::toInt( ObjectType::OBJECT_BLOCK_RED ) );
	mPhysicsBody->setContactTestBitmask( converter::toInt( ObjectType::OBJECT_ALL ) );
	mPhysicsBody->setCollisionBitmask( converter::toInt( ObjectType::OBJECT_BLOCK_RED ) );
	this->setPhysicsBody( mPhysicsBody );
}

bool RedBlock::isChange() const
{
	return mIsChanged;
}