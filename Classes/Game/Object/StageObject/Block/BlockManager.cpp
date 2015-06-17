#include "BlockManager.h"
#include "BlockDataReader.h"
#include "BlockFactory.h"

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
	
	auto fac = std::make_shared< BlockFactory >();
	fac->createBlock( mBlockNode, "Plist/stage1.plist" );
	
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