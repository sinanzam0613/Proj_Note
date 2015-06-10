#include "Block.h"
#include "../ObjectType.h"

using namespace cocos2d;

Block::Block()
	: mBlockData( BlockData() )
	, mIsTextureChanged( false )
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
	if (mIsTextureChanged)	return;

	if (static_cast<ObjectType>(mBlockData.objectType) == ObjectType::OBJECT_BLOCK_RED)
	{
		if (static_cast<ObjectType>(contactNode->getPhysicsBody()->getCategoryBitmask() ) == ObjectType::OBJECT_PLAYER_RED )
		{

			this->setTexture(mBlockData.blockTextureName);
			mIsTextureChanged = true;
			CCLOG("%s", this->getName().c_str());

			initPhysics();
		}
	}

	if (static_cast<ObjectType>(mBlockData.objectType) == ObjectType::OBJECT_BLOCK_BLUE)
	{
		if (static_cast<ObjectType>(contactNode->getPhysicsBody()->getCategoryBitmask()) == ObjectType::OBJECT_PLAYER_BLUE)
		{

			this->setTexture(mBlockData.blockTextureName);
			mIsTextureChanged = true;
			CCLOG("%s", this->getName().c_str());

			initPhysics();
		}
	}
}

void Block::initPhysics()
{
	auto size = cocos2d::Size( this->getContentSize().width, this->getContentSize().height );
	
	mPhysicsBody = PhysicsBody::createBox( size, mPhysicsMaterial );
	mPhysicsBody->setDynamic( false );
	mPhysicsBody->setCategoryBitmask( mBlockData.objectType );

	if (static_cast<ObjectType>(mBlockData.objectType) == ObjectType::OBJECT_BLOCK_RED)
	{
		mPhysicsBody->setContactTestBitmask(0xFFFFFFFF);
		mPhysicsBody->setCollisionBitmask(static_cast<int>(ObjectType::OBJECT_PLAYER_RED));
		this->setPhysicsBody(mPhysicsBody);
	}

	if (static_cast<ObjectType>(mBlockData.objectType) == ObjectType::OBJECT_BLOCK_BLUE)
	{
		mPhysicsBody->setContactTestBitmask(0xFFFFFFFF);
		mPhysicsBody->setCollisionBitmask(static_cast<int>(ObjectType::OBJECT_PLAYER_BLUE));
		this->setPhysicsBody(mPhysicsBody);
	}
}