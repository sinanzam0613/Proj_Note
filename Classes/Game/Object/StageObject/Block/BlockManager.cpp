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
	auto readData	= reader->read( "Plist/stage1.plist" );
	
	int count = 0;
	for ( auto& data : readData )
	{
		auto block = Block::create( "Block" + std::to_string( count ), data );
		mBlockNode->addChild( block );
		++count;
	}
	
	return true;
}

void BlockManager::onTouchBegan(cocos2d::Point pos) {
}

void BlockManager::onTouchMove(cocos2d::Point pos) {

}

void BlockManager::onTouchEnd(cocos2d::Point pos) {

}

Vec2 BlockManager::getBlockPos(int value) const {
	if (value >= mBlockNode->getChildrenCount()) {
		return mBlockNode->getChildren().front()->getPosition();
	}

	return mBlockNode->getChildren().at(value)->getPosition();
}