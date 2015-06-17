#include "BlueBlock.h"
#include "../ObjectType.h"

using namespace cocos2d;

BlueBlock::BlueBlock()
	: mBlockData( BlockData() )
	, mIsChanged( false )
{
	
}

BlueBlock::~BlueBlock()
{
	this->disableCollision( this->getName() );
}

BlueBlock* BlueBlock::create( const std::string& nodeName, const BlockData& data )
{
	auto inst = new BlueBlock();
	
	if ( inst && inst->init( nodeName, data ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool BlueBlock::init( const std::string& nodeName, const BlockData& data )
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

void BlueBlock::onContactBegin( Node* contactNode )
{
	if ( mIsChanged ) return;
	
	int contactBit = contactNode->getPhysicsBody()->getCategoryBitmask();
	
	if ( converter::toObjectType( contactBit ) == ObjectType::OBJECT_PLAYER_BLUE )
	{
		auto name = mBlockData.blockTextureName + "After";
		setTexture( name + ".png" );
		setName( name );
		mIsChanged = true;
		initPhysics();
	}
}

void BlueBlock::initPhysics()
{
	auto size = cocos2d::Size( this->getContentSize().width, this->getContentSize().height );
	
	mPhysicsBody = PhysicsBody::createBox( size, mPhysicsMaterial );
	mPhysicsBody->setDynamic( false );
	mPhysicsBody->setCategoryBitmask( converter::toInt( ObjectType::OBJECT_BLOCK_BLUE ) );
	mPhysicsBody->setContactTestBitmask( converter::toInt( ObjectType::OBJECT_ALL ) );
	mPhysicsBody->setCollisionBitmask( converter::toInt( ObjectType::OBJECT_BLOCK_BLUE ) );
	this->setPhysicsBody( mPhysicsBody );
}

bool BlueBlock::isChange() const
{
	return mIsChanged;
}