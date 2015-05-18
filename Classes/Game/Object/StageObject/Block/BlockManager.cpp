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
	
	int count = 0;
	for ( auto& data : readData )
	{
		auto block = Block::create( "Block" + std::to_string( count ), data );
		//mBlockList.push_back(block)5;
		mBlockNode->addChild( block );
		++count;
	}
	
	return true;
}

void BlockManager::onTouchBegan(cocos2d::Point pos) {
	//mBlockList.size();
}

void BlockManager::onTouchMove(cocos2d::Point pos) {

}

void BlockManager::onTouchEnd(cocos2d::Point pos) {

}

Vec2 BlockManager::getBlockPos(int value) const {
	if (value >= mBlockNode->getChildrenCount()) {
		return mBlockNode->getChildren().front()->getPosition();
	}

	//CCLOG("X : %f", mBlockList[value]->getPositionX());
	//CCLOG("Y : %f", mBlockList[value]->getPositionY());

	return mBlockNode->getChildren().at(value)->getPosition();
}