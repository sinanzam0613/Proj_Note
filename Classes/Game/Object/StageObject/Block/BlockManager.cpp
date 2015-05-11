#include "BlockManager.h"
#include "Block.h"
#include "BlockDataReader.h"

using namespace cocos2d;

BlockManager* BlockManager::create()
{
	auto inst = new BlockManager();
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool BlockManager::init()
{
	if ( !Node::init() )
	{
		return false;
	}
	
	mBlockNode = Node::create();
	this->addChild( mBlockNode );
	
	auto reader		= BlockDataReader::create();
	auto readData	= reader->read( "Plist/BlockData.plist" );
	
	for ( auto& data : readData )
	{
		auto block = Block::create( "Block" + std::to_string( readData.size() ), data );
		mBlockNode->addChild( block );
	}
	
	return true;
}