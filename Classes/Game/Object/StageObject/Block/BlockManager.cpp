#include "BlockManager.h"
#include "BlockDataReader.h"
#include "BlockFactory.h"

#include "Utility/Audio/ADX2Player.h"

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

	auto player = ADX2Player::create("Sound/ADX2/EffectUnit/SoundEffect.acb");
	player->setName("Player");
	addChild(player);
	
	auto fac = std::make_shared< BlockFactory >();
	fac->createBlock( mBlockNode, "Plist/Stage1.plist" );
	
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